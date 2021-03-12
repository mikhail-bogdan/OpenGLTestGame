#version 460 core
layout(location = 0) in vec2 pos; // <vec2 pos, vec2 tex_coord>
layout(location = 1) in vec2 tex_coords;
out vec3 ourColor;
out vec2 TexCoords;
uniform mat4 projection;
void main()
{
	gl_Position = projection * vec4(pos, 0.0, 1.0);
	ourColor = vec3(1.0, 1.0, 1.0);
	TexCoords = tex_coords;
}