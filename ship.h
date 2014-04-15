RenderObject * genShip(void)
{
	float temp[] = {
		-0.5f, 0.4f,0,
		 0.5f, 0.0f,0,
		-0.5f,-0.4f,0,
		-0.2f, 0.0f,0,
		-0.5f, 0.4f,0
	};

	return new RenderObject(temp,sizeof(temp)/sizeof(float));
}
