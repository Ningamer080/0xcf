#include "Shader.h"

static std::string loadShader(const std::string& fileName) {
	std::fstream file;
	std::string output;
	std::string line;

	file.open((fileName).c_str());

	if (file.is_open()) {
		while (file.good()) {
			std::getline(file, line);
			output.append(line + "\n");
		}
	}
	else {
		printerror("Failed to load shader file" + fileName);
	}

	return output;
}

static void checkShader(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage) {
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram) glGetProgramiv(shader, flag, &success);
	else glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE) {
		if (isProgram) glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}

static GLenum createShader(const std::string& source, GLenum shader_type) {
	GLuint shader = glCreateShader(shader_type);

	if (shader == 0) std::cerr << "GL Shader creating failed !" << std::endl;

	const GLchar* shaderSourceStrs[1];
	GLint shaderSourceStrLenghts[1];

	shaderSourceStrs[0] = source.c_str();
	shaderSourceStrLenghts[0] = source.length();

	glShaderSource(shader, 1, shaderSourceStrs, shaderSourceStrLenghts);
	glCompileShader(shader);
	checkShader(shader, GL_COMPILE_STATUS, false, "Failed to compile shader !");

	return shader;
}

Shader::Shader()
{

}

void Shader::createProgram(const char* frag, const char* vert) {
	m_program = glCreateProgram();
	m_shader[0] = createShader(loadShader(vert), GL_VERTEX_SHADER);
	m_shader[1] = createShader(loadShader(frag), GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(m_program, m_shader[i]);

	glBindAttribLocation(m_program, 0, "position");

	glLinkProgram(m_program);
	checkShader(m_program, GL_LINK_STATUS, true, "Shader program failed to link !");

	glValidateProgram(m_program);
	checkShader(m_program, GL_VALIDATE_STATUS, true, "Shader program failed to validate !");
}

void Shader::Bind() {
	glUseProgram(m_program);
}

Shader::~Shader()
{
	for (unsigned int i = 0; i < NUM_SHADERS; i++) glDetachShader(m_program, m_shader[i]), glDeleteShader(m_shader[i]);

	glDeleteProgram(m_program);
}