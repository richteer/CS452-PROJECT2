#version 130

uniform float angle;
uniform vec2 position;
uniform vec2 window;
uniform vec4 color;
uniform mat4 proj;

in vec3 point;
out vec4 outColor;

void main() {
	
	float x = window.x;
	float y = window.y;
	float zang = 0.1;//0.5235987755982988;
	

	mat3 rotation = mat3(cos(angle), sin(angle), 0,
					     -sin(angle), cos(angle), 0,
					     0,           0,          1);

	mat4 rz = mat4(1.0, 0.0, 0.0, 0.0,
				   0.0, cos(zang), -sin(zang), 0.0,
				   0.0, sin(zang),  cos(zang), 0.0,
				   0.0, 0.0, 0.0, 1.0);


	mat4 translation = mat4(1.0, 0.0, 0.0, position.x,
						 	0.0, 1.0, 0.0, position.y,
						 	0.0, 0.0, 1.0, 1.0,
							0.0, 0.0, 0.0, 1.0);

	mat3 scale = mat3(  1.0/x, 0.0,   0.0,
						0.0,   1.0/y, 0.0,
						0.0,   0.0,   1.0);
/*
	mat4 projection = mat4( 1.0/x, 0.0,   0.0, 0.0,
							0.0,   1.0/y, 0.0, 0.0,
							0.0,   0.0,   1.0, 0.0,
							0.0,   0.0,   0.0, 1.0);
*/

	translation = transpose(translation);
		
	gl_Position = proj * (translation * vec4(rotation * (point), 1.0));
	outColor = color;
}
