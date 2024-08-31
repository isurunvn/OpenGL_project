#include<GL/glut.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <GL/gl.h>
#include <unistd.h>


float horsePosition = 0.0f;
float horseDirection = 0.0f;
float horseTail = 0.0f;
float boatPosition = 0.0f;
float pedalRotation = 0.0f;
float circlePosition = 800.0f;
float RightflowerPotScale1 = 0.8f;
float RightflowerPotScale2 =0.6f;
float leftFlowerScale = 0.6f;
float rightFishScale = 0.5f;

bool movingHorse = false;
bool rotatingHorse = false;
bool rotatingTail = false;
bool rotatingPadel = false;
bool movingBoat = false;
bool movingSun = false;


void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 800.0);
}


void Circle(float cx, float cy, float radius, int num_segments) {
    glBegin(GL_POLYGON);

    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / (float)num_segments;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void House(){

    glColor3f(0.5f, 0.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(100, 0);
    glVertex2d(100, 90);
    glVertex2d(0, 90);
    glEnd();

    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2d(-20, 90);
    glTexCoord2f(1.0f, 0.0f); glVertex2d(120, 90);
    glTexCoord2f(1.0f, 1.0f); glVertex2d(100, 120);
    glTexCoord2f(0.0f, 1.0f); glVertex2d(0, 120);
    glEnd();

    glColor3f(0.8f, 0.8f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2d(35, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex2d(65, 0);
    glTexCoord2f(1.0f, 1.0f); glVertex2d(65, 60);
    glTexCoord2f(0.0f, 1.0f); glVertex2d(35, 60);
    glEnd();

}


void FlowerPot(float centerX, float centerY)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    Circle(centerX - 20, centerY + 25, 10,50);

    glColor3f(1.0f, 0.5f, 0.5f);
    Circle(centerX + 20, centerY + 35, 10, 50);

    glColor3f(0.5f, 0.0f, 0.5f);
    Circle(centerX, centerY + 60, 10,50);

    glColor3f(0.8f, 0.6f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(centerX - 10, centerY - 40);
    glVertex2f(centerX + 10, centerY - 40);
    glVertex2f(centerX + 20, centerY);
    glVertex2f(centerX - 20, centerY);
    glEnd();

    glColor3f(0.8f, 0.6f, 0.2f);
    glBegin(GL_LINES);
    glVertex2f(centerX, centerY);
    glVertex2f(centerX, centerY + 50);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(centerX, centerY + 25);
    glVertex2f(centerX - 10, centerY + 25);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(centerX, centerY + 35);
    glVertex2f(centerX + 10, centerY + 35);
    glEnd();
}


void yellowFish(){

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(-40.0, 0.0);
    glVertex2f(0.0, -30.0);
    glVertex2f(40.0, 0.0);
    glVertex2f(0.0, 30.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(40.0,0.0);
    glVertex2f(80.0,-30.0);
    glVertex2f(80.0,30.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(20.0,15.0);
    glVertex2f(30.0,45.0);
    glVertex2f(0.0,30.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(20.0, -15.0);
    glVertex2f(30.0, -45.0);
    glVertex2f(0.0, -30.0);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-25.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0,30.0f);
    glVertex2f(0.0,-30.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(20.0,15.0f);
    glVertex2f(20.0,-15.0f);
    glEnd();
}


void purpleFish(){

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.5f);
    glVertex2f(-40.0, 0.0);
    glVertex2f(0.0, -30.0);
    glVertex2f(40.0, 0.0);
    glVertex2f(0.0, 30.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.2f, 0.4f);
    glVertex2f(40.0,0.0);
    glVertex2f(80.0,-30.0);
    glVertex2f(80.0,30.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.2f, 0.4f);
    glVertex2f(-20.0,55.0);
    glVertex2f(0.0,30.0);
    glVertex2f(20.0,55.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.2f, 0.4f);
    glVertex2f(-20.0, -55.0);
    glVertex2f(20.0, -55.0);
    glVertex2f(0.0, -30.0);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(0.8f, 0.2f, 0.4f);
    glVertex2f(-25.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.8f, 0.2f, 0.4f);
    glVertex2f(0.0,30.0f);
    glVertex2f(0.0,-30.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.8f, 0.2f, 0.4f);
    glVertex2f(20.0,15.0f);
    glVertex2f(20.0,-15.0f);
    glEnd();

}


void boat(){

    glTranslatef(boatPosition, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.6f, 0.2f);
    glVertex2f(-60.0,-50.0);
    glVertex2f(60.0,-50.0);
    glVertex2f(80.0,0.0);
    glVertex2f(-80.0,0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-60.0,0.0f);
    glVertex2f(-20.0,0.0f);
    glVertex2f(-30.0,20.0f);
    glVertex2f(-50.0,20.0f);
    glVertex2f(-30.0,40.0f);
    glVertex2f(-60.0,40.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-60.0,40.0);
    glVertex2f(-40.0,40.0);
    glVertex2f(-40.0,50.0);
    glVertex2f(-35.0,50.0);
    glVertex2f(-40.0,60.0);
    glVertex2f(-60.0,60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-60.0,60.0);
    glVertex2f(-40.0,60.0);
    glVertex2f(-35.0,70.0);
    glVertex2f(-60.0,70.0);
    glEnd();

    glPushMatrix();

    glTranslatef(-30.0f, 20.0f, 0.0f);

    glRotatef(pedalRotation, 0.0f, 0.0f, 1.0f);

    glTranslatef(30.0f, -20.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-75.0f, -70.0f);
    glVertex2f(-65.0f, -70.0f);
    glVertex2f(-30.0f, 20.0f);
    glEnd();

    glPopMatrix();

}


void horse(){

    glTranslatef(horsePosition, 0.0f, 0.0f);
    glRotatef(horseDirection, 0.0f, 1.0f, 0.0f);

    glBegin(GL_POLYGON);

    glColor3f(0.71f, 0.4f, 0.11f);

    glVertex2f(0.0f,50.0f);
    glVertex2f(0.0f,0.0f);
    glVertex2f(80.0f,0.0f);
    glVertex2f(80.0f,40.0f);
    glVertex2f(20.0f,40.0f);
    glVertex2f(-10.0f,90.0f);
    glVertex2f(-20.0f,70.0f);
    glVertex2f(-30.0f,70.0f);
    glVertex2f(-30.0f,50.0f);
    glVertex2f(-20.0f,60.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.0f,-30.0f);
    glVertex2f(20.0f,-30.0f);
    glVertex2f(20.0f,0.0f);
    glVertex2f(0.0f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(60.0f,-30.0f);
    glVertex2f(80.0f,-30.0f);
    glVertex2f(80.0f,0.0f);
    glVertex2f(60.0f,0.0f);
    glEnd();

    glPushMatrix();

    glTranslatef(80.0f, 40.0f, 0.0f);
    glRotatef(horseTail, 0.0f, 0.0f, 1.0f);
    glTranslatef(-80.0f, -40.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(80.0f,40.0f);
    glVertex2f(100.0f,40.0f);
    glVertex2f(90.0f,-10.0f);

    glEnd();
    glPopMatrix();

    glPointSize(4.0);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-10.0, 70.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(-10.0f,90.0f);
    glVertex2f(20.0f,40.0f);
    glVertex2f(40.0f,40.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(-20.0f,70.0f);
    glVertex2f(-20.0f,50.0f);
    glEnd();
}


void trees(){

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.165f, 0.165f);
    glVertex2d(-20, -60);
    glVertex2d(20, -60);
    glVertex2d(20, 0);
    glVertex2d(-20, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3d(0, 0.5, 0);
    glVertex2d(-60, 0);
    glVertex2d(60, 0);
    glVertex2d(0, 80);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3d(0, 0.5, 0);
    glVertex2d(-40, 60);
    glVertex2d(40, 60);
    glVertex2d(0, 120);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3d(0, 0.5, 0);
    glVertex2d(-20, 100);
    glVertex2d(20, 100);
    glVertex2d(0, 180);
    glEnd();

}


void fruitTree(){

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.165f, 0.165f);
    glVertex2d(-20, -60);
    glVertex2d(20, -60);
    glVertex2d(20, 0);
    glVertex2d(-20, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3d(0, 0.5, 0);
    glVertex2d(-60, 0);
    glVertex2d(60, 0);
    glVertex2d(0, 80);
    glEnd();

    glBegin(GL_LINES);
    glColor3d(0,0,0);
    glVertex2d(-30,0);
    glVertex2d(-30,-30);
    glEnd();

    glBegin(GL_LINES);
    glColor3d(0,0,0);
    glVertex2d(30,0);
    glVertex2d(30,-30);
    glEnd();

    glColor3f(1.0f,0.0f,0.0f);
    Circle(-30,-30,3,7);
    Circle(30,-30,3,7);

    glBegin(GL_TRIANGLES);
    glColor3d(0, 0.5, 0);
    glVertex2d(-40, 60);
    glVertex2d(40, 60);
    glVertex2d(0, 120);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3d(0, 0.5, 0);
    glVertex2d(-20, 100);
    glVertex2d(20, 100);
    glVertex2d(0, 180);
    glEnd();

}


void keyboard(unsigned char key, int x, int y){

    switch (key){

        case 'f':
            movingHorse = true;
            break;

        case 'q':
            rotatingHorse = true;
            break;

        case 'r':
            rotatingTail = true;
            break;

        case 'b':
            movingBoat = true;
            break;

        case 'w':
            rotatingPadel = true;
            break;

        case ' ':
            movingSun = true;
            break;

        case 'z':
            movingHorse = false;
            rotatingHorse = false;
            rotatingTail = false;
            movingBoat = false;
            rotatingPadel = false;
            movingSun = false;
            rightFishScale = 0.5f;
            leftFlowerScale = 0.6f;
            RightflowerPotScale1 = 0.8f;
            RightflowerPotScale2 = 0.6f;
            break;
    }

    if (key == 'u'){
        rightFishScale = 2*rightFishScale;
        leftFlowerScale = 2*leftFlowerScale;
    } else if (key == 's'){
        RightflowerPotScale1 = 0.8 * RightflowerPotScale1;
        RightflowerPotScale2 = 0.8 * RightflowerPotScale2;
    } else if (key == ' '){
        RightflowerPotScale1 = 0.6f;
    }

}


void animation(int value) {
    if (movingHorse) {
        if (horseDirection == 0.0f){
            horsePosition -= 2.0f;
            if (horsePosition < -500.0f) {
                horsePosition = 500.0f;
            }
        } else {
            horsePosition += 2.0f;
            if (horsePosition > 650.0f) {
                horsePosition = -500.0f;
            }
        }
    } else{
        horsePosition = 0.0f;
    }

    if (rotatingTail) {
        horseTail -= 2.0f;
        if (horseTail >= 360.0f) {
            horseTail = 0.0f;
        }
    }

    if (rotatingHorse) {
        if (horseDirection == 0.0f) {
            horseDirection = 180.0f;
            rotatingHorse = false;
        } else {
            horseDirection = 0.0f;
            rotatingHorse = false;
        }
    }

    if (movingBoat) {
        boatPosition += 2.0f;
        if (boatPosition > 500.0f){
            boatPosition = -500.0f;
        }

    }

    if (movingSun) {
        circlePosition -= 0.25f;
        if (circlePosition < 0.0f){
            circlePosition = 1000.0f;
        }
    }

    if (rotatingPadel){
        pedalRotation -= 2.0f;
        if (pedalRotation <-30.0f){
            pedalRotation = 0.0f;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(20, animation, 0);
}



void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1000.0f, 0.0f);
    glVertex2f(1000.0f, 800.0f);
    glVertex2f(0.0f, 800.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.529f, 0.808f, 0.922f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1000.0f, 0.0f);
    glVertex2f(1000.0f, 200.0f);
    glVertex2f(0.0f, 200.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(750.0f,420.0f,0.0f);
    fruitTree();
    glPopMatrix();


    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex2f(0.0f, 200.0f);
    for (int x = 0; x <= 1000; x++) {
    float y = 400 + 30 * sin(2 * M_PI * (x / 1000.0f));
    glVertex2f(x, y);}
    glVertex2f(1000.0f, 200.0f);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    Circle(circlePosition,700.0,30.0,100);

    glPushMatrix();
    glTranslatef(250.0f, 390.0f, 0.0f);
    glEnable(GL_TEXTURE_2D);
    House();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(450.0f,420.0f,0.0f);
    fruitTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(600.0f, 350.0f, 0.0f);
    glEnable(GL_TEXTURE_2D);
    House();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50.0f,400.0f,0.0f);
    trees();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400.0f,300.0f,0.0f);
    horse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100.0f,250.0f,0.0f);
    glScalef(leftFlowerScale,leftFlowerScale,1.0f);
    glTranslatef(-100.0f,-250.0f,0.0f);
    FlowerPot(100.0f,250.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150.0f,280.0f,0.0f);
    glScalef(leftFlowerScale,leftFlowerScale,1.0f);
    glTranslatef(-150.0f,-280.0f,0.0f);
    FlowerPot(150.0f, 280.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(800.0f,250.0f,0.0f);
    glScalef(RightflowerPotScale1,RightflowerPotScale1,1.0f);
    glTranslatef(-800.0f,-250.0f,0.0f);
    FlowerPot(800.0f, 250.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(700.0f,230.0f,0.0f);
    glScalef(RightflowerPotScale2,RightflowerPotScale2,1.0f);
    glTranslatef(-700.0f,-230.0f,0.0f);
    FlowerPot(700.0f, 230.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(200.0f,170.0f,0.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    yellowFish();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(80.0f,120.0f,0.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    yellowFish();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(700.0f,100.0f,0.0f);
    glScalef(rightFishScale, rightFishScale, 1.0f);
    purpleFish();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(850.0f,130.0f,0.0f);
    glScalef(rightFishScale, rightFishScale, 1.0f);
    purpleFish();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400.0f,170.0f,0.0f);
    glScalef(1.4f,1.4f,1.0f);
    boat();
    glPopMatrix();

    glutSwapBuffers();
}


int main(int argc, char**argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Take home assignment");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(20, animation, 0);
    glutMainLoop();
    return 0;

}
