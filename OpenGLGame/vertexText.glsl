#version 460 core
layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texCoord;
uniform mat4 transform;
out vec2 v_texCoord;
void main ( )
{
	gl_Position = transform * vec4 ( position, 0.0, 1.0 );
	v_texCoord = texCoord;
}