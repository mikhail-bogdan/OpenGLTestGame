#include "Graphics.h"
#include <chrono>
#include <map>
#include <ft2build.h>
#include <fstream>
#include FT_FREETYPE_H

Graphics* Graphics::graphics = nullptr;
/*
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	Graphics::getGraphics()->resizeWindow(width, height);
}
*/
struct Character {
	GLuint     TextureID; // ID текстуры глифа
	glm::ivec2 Size;      // Размеры глифа
	glm::ivec2 Bearing;   // Смещение верхней левой точки глифа
	GLuint     Advance;   // Горизонтальное смещение до начала следующего глифа
};

std::map<GLchar, Character> Characters;
FT_Library ft;
FT_Face face;

Graphics::Graphics()
{

	this->width = 800;
	this->height = 600;
	
	int code = SDL_Init(SDL_INIT_EVERYTHING);

	this->window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GLContext context = SDL_GL_CreateContext(this->window);

	glewExperimental = true;
	GLenum e = glewInit();

	SDL_GL_SetSwapInterval(1);

	/*glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);


	window = glfwCreateWindow(this->width, this->height, "test", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSetWindowSizeCallback(window, framebuffer_size_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
	glfwSwapInterval(1);*/
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Graphics::Init()
{
	

	graphics = new Graphics();
	//FT_Init_FreeType(&ft);


	//FT_New_Face(ft, "arial.ttf", 0, &face);

	//FT_Set_Pixel_Sizes(face, 0, 48);

	
	

	
	

	

	/*glViewport(0, 0, 800, 600);
	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (GLubyte c = 0; c < 128; c++)
	{
		// Load character glyph
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
			continue;
		}
		// Generate texture
		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer
		);
		// Set texture options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// Now store character for later use
		Character character = {
			texture,
			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			face->glyph->advance.x
		};
		Characters.insert(std::pair<GLchar, Character>(c, character));
		// Characters[c] = character;
	}

	float vertices[] = {
		-0.5, -0.5, 0,
		0.5, -0.5, 0,
		0, 0.5, 0,
	};
	for (int i = 0; i < 9; i++) {
		vertices[i] *= 25;
		vertices[i] += 25;
	}

	float vertices2[] = {
		-0.5, 0.5, 0,
		-0.5, -0.5, 0,
		0.5, -0.5, 0,
		-0.5, 0.5, 0,
		0.5, 0.5, 0,
		0.5, -0.5, 0,
	};

	const char* textVertexShaderSource = "#version 460 core\n"
		"layout(location = 0) in vec4 vertex; // <vec2 pos, vec2 tex_coord>\n"
		"out vec2 TexCoords;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
			"gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);\n"
			"TexCoords = vertex.zw;\n"
		"}\0";

	const char* textFragmentShaderSource = "#version 460 core\n"
		"in vec2 TexCoords;\n"
		"out vec4 color;\n"
		"uniform sampler2D text;\n"
		"uniform vec3 textColor;\n"
		"void main()\n"
		"{\n"
			"vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);\n"
			"color = vec4(textColor, 1.0) * sampled;\n"
		"}\0";

	const char* vertexShaderSource = "#version 460 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
			"gl_Position = projection * vec4(aPos.xy, 0.0, 1.0);\n"
		"}\0";

	const char* fragmentShaderSource = "#version 460 core\n"
		"out vec4 FragColor;\n"
		"uniform vec4 ourColor;\n"
		"void main()\n"
		"{\n"
			"FragColor = ourColor;\n"
		"}\0";

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	while(!glfwWindowShouldClose(window))
	{
		glClearColor(0, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		

		

		GLuint VBO2;
		glGenBuffers(1, &VBO2);

		GLuint VAO2;
		glGenVertexArrays(1, &VAO2);

		glBindVertexArray(VAO2);

		glBindBuffer(GL_ARRAY_BUFFER, VBO2);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
		


		
		GLuint VBO;
		glGenBuffers(1, &VBO);

		GLuint VAO;
		glGenVertexArrays(1, &VAO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		GLuint vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		GLuint fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		GLuint shaderProgram;
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		
		glBindVertexArray(VAO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		float timeValue = glfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
		glUseProgram(shaderProgram);
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
		unsigned int transformLoc = glGetUniformLocation(shaderProgram, "projection");
		glm::mat4 trans = glm::mat4(1.0f);
		trans = projection;
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(projection));

		
		
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexArrayAttrib(VAO, 0);

		//glDeleteVertexArrays(1, &VAO);
		//glDeleteBuffers(1, &VBO);


		
		glBindBuffer(GL_ARRAY_BUFFER, VBO2);
		glBindVertexArray(VAO2);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		timeValue = glfwGetTime();
		greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
		glUseProgram(shaderProgram);
		glUniform4f(vertexColorLocation, 1.0f, 0, 0.0f, 1.0f);
		transformLoc = glGetUniformLocation(shaderProgram, "projection");
		trans = projection;
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(projection));

		
		glDrawArrays(GL_TRIANGLES, 0, 6);

		*/
		/*GLuint VAO, VBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		*/


		
}

SDL_Event* Graphics::PollEvent()
{
	SDL_Event* event = new SDL_Event;
	if (SDL_PollEvent(event) == 0) return nullptr;
	return event;
}

void Graphics::Update(SDL_Event* event)
{
	glClearColor(0, 1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto iter = this->renderers.begin(); iter != this->renderers.end(); iter++)
	{
		(*iter)->render(this->projection);
	}
	
	/*glfwSwapBuffers(this->window);
	glfwPollEvents();*/

	SDL_GL_SwapWindow(this->window);

	
	return;
}

void Graphics::DeInit()
{
	FT_Done_Face(face);   // Завершение работы с шрифтом face
	FT_Done_FreeType(ft); // Завершение работы FreeType
	//glfwTerminate();
	delete graphics;
}

Graphics* Graphics::getGraphics()
{
	return Graphics::graphics;
}

bool Graphics::IsGraphicsInit()
{
	return graphics != nullptr;
}

void Graphics::resizeWindow(int width, int height)
{
	this->width = width;
	this->height = height;
	glViewport(0, 0, width, height);
	this->projection.setOrtho(0.0f, (float)width, 0.0f, (float)height, 0, 1);
}

bool Graphics::isWindowShouldClose()
{
	return false;//glfwWindowShouldClose(window);
}

Vector2 Graphics::GetWindowSize() const
{
	return Vector2(width, height);
}

void Graphics::addRenderer(Renderer* renderer)
{
	this->renderers.push_back(renderer);
}

void Graphics::removeRenderer(Renderer* renderer)
{
	this->renderers.remove(renderer);
}