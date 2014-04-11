#version 130

uniform float angle;
in vec3 point;

out vec4 color;

void main() {
	
	color = vec4(1.0f,1.0f,1.0f,1.0f);
	gl_Position = vec4(mat3(cos(angle),  sin(angle), 0,
					        -sin(angle), cos(angle), 0,
					        0,           0,          1) * point, 1.0f);


	//gl_Position = vec4(point,1.0f);

}
