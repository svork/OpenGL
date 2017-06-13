#include <glut.h>

GLfloat angle, fAspect, win;

GLfloat angulo = 15.0f; // Angulo de Rotacao

GLfloat posX = 0.0f, posY = 0.0f;

// Função callback para fazer o desenho
void Desenha(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Assento do banco
	glPushMatrix(); // Inicio do objeto
	glTranslatef(1.0f, 1.0f, 1.0f); // Movimenta o assento do banco para o centro da tela	
	glScalef(4.0f, 0.1f, 1.0f); // Transforma o cubo em assento do banco
	glColor3f(0.5f, 0.3f, 0.2f); // Cor do banco da praca - Marrom
	glutSolidCube(25.0f); // Cria o cubo
	glPopMatrix(); // Fim do objeto

	// Encosto do banco
	glPushMatrix();
	glTranslatef(1.0f, 12.75f, -13.5f);
	glScalef(6.0f, 1.5f, 0.2f);
	glColor3f(0.5f, 0.3f, 0.2f);
	glutSolidCube(15.0f);
	glPopMatrix();

	// Perna 1
	glPushMatrix();
	glTranslatef(-30.0f, -15.0f, 10.0f);	
	glScalef(0.3f, 2.0f, 0.2f);
	glColor3f(0.5f, 0.3f, 0.2f);
	glutSolidCube(15.0f);	
	glPopMatrix();

	// Perna 2
	glPushMatrix();
	glTranslatef(30.0f, -15.0f, 10.0f);	
	glScalef(0.3f, 2.0f, 0.2f);
	glColor3f(0.5f, 0.3f, 0.2f);
	glutSolidCube(15.0f);	
	glPopMatrix();

	// Perna 3
	glPushMatrix();
	glTranslatef(-30.0f, -15.0f, -10.0f);	
	glScalef(0.3f, 2.0f, 0.2f);
	glColor3f(0.5f, 0.3f, 0.2f);
	glutSolidCube(15.0f);	
	glPopMatrix();

	// Perna 4
	glPushMatrix();
	glTranslatef(30.0f, -15.0f, -10.0f);	
	glScalef(0.3f, 2.0f, 0.2f);
	glColor3f(0.5f, 0.3f, 0.2f);
	glutSolidCube(15.0f);	
	glPopMatrix();	

	// Gramado	
	glPushMatrix();
	glTranslatef(1.0f, -30.0f, 1.0f);	
	glScalef(10.0f, 0.1f, 10.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glutSolidCube(25.0f);	
	glPopMatrix();

	// Poste de Luz
	glPushMatrix();
	glTranslatef(-90.0f, 40.0f, -50.0f);	
	glScalef(0.2f, 10.0f, 0.2f);
	glColor3f(0.1f, 0.1f, 0.0f);
	glutSolidCube(15.0f);	
	glPopMatrix();

	// Luz do Poste
	glPushMatrix();
	glTranslatef(-90.0f, 120.0f, -50.0f);	
	glScalef(1.0f, 1.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidSphere(10.0, 10, 10);	
	glPopMatrix();

	// Tronco da Arvore
	glPushMatrix();
	glTranslatef(90.0f, 40.0f, 80.0f);
	glScalef(0.8f, 10.0f, 0.8f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidCube(15.0f);
	glPopMatrix();

	// Folhas do Pinheiro, um cone
	glPushMatrix();
	glTranslatef(90.0f, 40.0f, 80.0f);
	glRotatef(90.0f, -90.0f, 1.0f, 1.0f);
	glScalef(1.0f, 1.0f, 2.0f);
	glColor3f(0.0f, 1.0f, 0.0f);	
	glutSolidCone(40.0, 50.0, 10, 10);
	glPopMatrix();

	// Executa os comandos OpenGL
	glutSwapBuffers();
}

// Inicializa parametros de rendering
void Inicializa(void) {
	GLfloat luzAmbiente[4] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat luzDifusa[4] = { 0.7, 0.7, 0.7, 1.0 }; // Cor
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 }; // Brilho
	GLfloat posicaoLuz[4] = { 0.0, 50.0, 50.0, 1.0 };

	// Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLint especMaterial = 60;

	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorizacao de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletancia do material
	//glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);

	// Define a concentracao do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parametros da luz de numero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	// Habilita a definicao da cor do material a partir da cor atual
	glEnable(GL_COLOR_MATERIAL);

	// Habilita o uso de iluminacao
	glEnable(GL_LIGHTING);

	// Habilita a luz de numero 0
	glEnable(GL_LIGHT0);

	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	angle = 45;

	win = 250.0f;
}

// Funcao usada para especificar o volume de visualizacao
void EspecificaParametrosVisualizacao(void) {
	// Especifica sistema de coordenadas de projecao
	glMatrixMode(GL_PROJECTION);

	// Inicializa sistema de coordenadas de projecao
	glLoadIdentity();

	// Especifica a projecao perspectiva
	gluPerspective(angle, fAspect, 0.1, 500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);

	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posicao do observador e do alvo
	gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);
}

// Funcao callback chamada quando o tamanho da janela e alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
	// Para evitar divisao por zero
	if (h == 0) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a correcao de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-win, win, -win, win);

	EspecificaParametrosVisualizacao();
}

// Funcao callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) { // zoom in
			if (angle >= 10) angle -= 5;
		}

	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) { // zoom out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Funcao callback chamada para gerenciar eventos do teclado
void GerenciaTeclado(unsigned char key, int x, int y) {
	switch (key) {
	case 'R':
	case 'r': // Muda a cor para vermelho
		glColor3f(1.0f, 0.0f, 0.0f);
		break;

	case 'G':
	case 'g': // Muda a cor para verde
		glColor3f(0.0f, 1.0f, 0.0f);
		break;

	case 'B':
	case 'b': // Muda a cor para azul
		glColor3f(0.0f, 0.0f, 1.0f);
		break;

	case 'Z':
	case 'z': // Rotacao positiva no eixo X
		glRotatef(angulo, 1.0f, 0.0f, 0.0f);
		break;

	case 'X':
	case 'x': // Rotacao negativa no eixo X
		glRotatef(-angulo, 1.0f, 0.0f, 0.0f);
		break;

	case 'A':
	case 'a': // Rotacao positiva no eixo Y
		glRotatef(angulo, 0.0f, 1.0f, 0.0f);
		break;

	case 'S':
	case 's': // Rotacao negativa no eixo Y
		glRotatef(-angulo, 0.0f, 1.0f, 0.0f);
		break;

	case 'Q':
	case 'q': // Rotacao positiva no eixo Z
		glRotatef(angulo, 0.0f, 0.0f, 1.0f);
		break;

	case 'W':
	case 'w': // Rotacao negativa no eixo Z
		glRotatef(-angulo, 0.0f, 0.0f, 1.0f);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

// Funcao callback chamada para gerenciar eventos do teclado (especiais)
void TeclasEspeciais(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		glTranslatef(0.0f, 15.0f, 0.0f);
	}
	if (key == GLUT_KEY_DOWN) {
		glTranslatef(0.0f, -15.0f, 0.0f);
	}
	if (key == GLUT_KEY_RIGHT) {
		glTranslatef(15.0f, 0.0f, 0.0f);
	}
	if (key == GLUT_KEY_LEFT) {
		glTranslatef(-15.0f, 0.0f, 0.0f);
	}
	glutPostRedisplay();
}

// Programa Principal
int main(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Rodrigo Costa 52718 - Cenario Open GL");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(GerenciaTeclado);
	glutSpecialFunc(TeclasEspeciais);
	Inicializa();
	glutMainLoop();
	return 0;
}