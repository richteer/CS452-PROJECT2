#define ONE -20.0f, 20.0f,-0.5f,
#define TWO 40.0f,  0.0f,-0.5f,
#define THREE -20.0f,-20.0f,-0.5f,
#define FOUR 0.0f,  0.0f, 0.0f,



RenderObject * genShip(void)
{
	float temp[] = {
/*		-20.0f, 16.0f,0,
		 20.0f, 0.0f,0,
		-20.0f,-16.0f,0,
		-16.0f, 0.0f,0,
		-20.0f, 16.0f,0
*/
		ONE
		TWO
		THREE
		ONE	
	
		ONE
		FOUR
		TWO

		TWO
		FOUR
		THREE

		THREE
		FOUR
		ONE




		/*-20.0f, 0.0f,-0.5f,
		  0.0f, 0.0f, 0.5f,
		 20.0f, 0.0f,-0.5f,*/
	};

	return new RenderObject(temp,sizeof(temp)/sizeof(float));
}
