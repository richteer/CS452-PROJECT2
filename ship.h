
RenderObject * genShip(void)
{
	float temp[] = {
		-20.0f, 16.0f,0,
		 20.0f, 0.0f,0,
		-20.0f,-16.0f,0,
		-16.0f, 0.0f,0,
		-20.0f, 16.0f,0
	};

	return new RenderObject(temp,sizeof(temp)/sizeof(float));
}
