#version 130

in vec3 point;
in float angle;

out vec4 color;

void main() {
	
	gl_Position = vec4(mat3(cos(angle), sin(angle),0,
					   -sin(angle),cos(angle),0,
					   0,          0,         1) * point, 0);
	color = vec4(1.0f,1.0f,1.0f,1.0f);

}
