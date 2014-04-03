#version 130

in vec2 point;
in float angle;

main() {
	gl_Position = vec3(cos(angle),sin(angle),0,
					   -sin(angle),cos(angle),0,
					   0,0,1) * vec(point, 1);

}
