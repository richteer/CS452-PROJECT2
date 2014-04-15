#version 130

uniform float angle;
uniform vec2 position;

in vec3 point;

out vec4 color;

void main() {
	
	color = vec4(1.0f,1.0f,1.0f,1.0f);

	mat3 rotation = mat3(cos(angle), sin(angle), 0,
					     -sin(angle), cos(angle), 0,
					     0,           0,          1);

	mat4 translation = mat4(1.0, 0.0, 0.0, position.x,
						 	0.0, 1.0, 0.0, position.y,
						 	0.0, 0.0, 1.0, 1.0,
							0.0, 0.0, 0.0, 1.0);


	translation = transpose(translation);
	

	gl_Position = translation * vec4(rotation * point, 1.0);
}
