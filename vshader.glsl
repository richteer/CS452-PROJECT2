#version 130

uniform float angle;
uniform vec2 position;
uniform vec2 window;
uniform vec4 color;

in vec3 point;
out vec4 outColor;

void main() {
	
	float x = window.x;
	float y = window.y;

	mat3 rotation = mat3(cos(angle), sin(angle), 0,
					     -sin(angle), cos(angle), 0,
					     0,           0,          1);

	mat4 translation = mat4(1.0, 0.0, 0.0, position.x,
						 	0.0, 1.0, 0.0, position.y,
						 	0.0, 0.0, 1.0, 1.0,
							0.0, 0.0, 0.0, 1.0);

	mat3 scale = mat3(  1.0/x, 0.0,   0.0,
						0.0,   1.0/y, 0.0,
						0.0,   0.0,   1.0);

	mat4 projection = mat4( 1.0/x, 0.0,   0.0, 0.0,
							0.0,   1.0/y, 0.0, 0.0,
							0.0,   0.0,   1.0, 0.0,
							0.0,   0.0,   0.0, 1.0);


	translation = transpose(translation);
		
	gl_Position = projection * (translation * vec4(rotation * (point), 1.0));
	outColor = color;
}
