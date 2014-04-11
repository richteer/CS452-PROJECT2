#version 130

in vec2 point;
in float angle;

void main() {
	
	gl_Position = vec4(mat3(cos(angle), sin(angle),0,
					   -sin(angle),cos(angle),0,
					   0,          0,         1) * vec3(point, 1), 0);

}
