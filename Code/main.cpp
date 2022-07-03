
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<string.h>
#include<vector>

float v[72][2]={{440,400},{560,400},{560,600},{440,600}, //Router
                {660,400},{940,400},{940,480},{660,480}, //Output Ports
                {660,520},{940,520},{940,600},{660,600}, //Output Ports
                {60,400},{340,400},{340,480},{60,480}, //Input Ports
                {60,520},{340,520},{340,600},{60,600},//Input Ports
                {680,410},{760,410},{760,470},{680,470}, //Output Boxes
                {770,410},{850,410},{850,470},{770,470}, //Output Boxes
                {680,530},{760,530},{760,590},{680,590}, //Output Boxes
                {770,530},{850,530},{850,590},{770,590}, //Output Boxes
                {860,420},{920,420},{920,460},{860,460}, //Output Boxes
                {860,540},{920,540},{920,580},{860,580}, //Output Boxes
                {150,410},{230,410},{230,470},{150,470}, //Input Boxes
                {240,410},{320,410},{320,470},{240,470}, //Input Boxes
                {150,530},{230,530},{230,590},{150,590}, //Input Boxes
                {240,530},{320,530},{320,590},{240,590}, //Input Boxes
                {80,420},{140,420},{140,460},{80,460}, //Input Boxes
                {80,540},{140,540},{140,580},{80,580}, //Input Boxes
                {440,800},{560,800},{560,870},{440,870} //Router processor
                };

float l[26][2]={{20,750},{980,750},{280,835},{440,835},{280,835},{280,590},{280,530},{280,470},
{400,290},{400,120},
{340,240},{660,240},
{340,180},{660,180},
{460,290},{460,120},
{520,290},{520,120},
{340,290},{340,120},
{340,120},{660,120},
{340,290},{660,290},
{660,290},{660,120}};
float offsetx=0,offsety=0;
int flag=0,color=0;
int displayscreen1,displayscreen2;

void init(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glLoadIdentity();
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,1000,0,1000);
    glMatrixMode(GL_MODELVIEW);

}

void arrow()
{
    glLineStipple(1, 0xffff);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINE_LOOP);
    glVertex2f(500,800);
    glVertex2f(520,770);
    glVertex2f(505,780);
    glVertex2f(505,620);
    glVertex2f(520,630);
    glVertex2f(500,600);
    glVertex2f(480,630);
    glVertex2f(495,620);
    glVertex2f(495,780);
    glVertex2f(480,770);
    glEnd();
}

void print(int x, int y, char *string)
{
//set the position of the text in the window using the x and y coordinates
glRasterPos2f(x,y);
//get the length of the string to display
int len = (int) strlen(string);

//loop to display character by character
for (int i = 0; i < len; i++)
{
glutBitmapCharacter(GLUT_BITMAP_8_BY_13,string[i]);
}
glEnd();
};

void OutLine(int a,int b,int c,int d)
{
    glColor3f(0,0,0);
    glLineStipple(1, 0xffff);
    glEnable(GL_LINE_STIPPLE);
     glBegin(GL_LINE_LOOP);
        glVertex2fv(v[a]);
        glVertex2fv(v[b]);
        glVertex2fv(v[c]);
        glVertex2fv(v[d]);
        glEnd();
}

void polygon(int a,int b,int c,int d)
{
     glBegin(GL_POLYGON);
        glVertex2fv(v[a]);
        glVertex2fv(v[b]);
        glVertex2fv(v[c]);
        glVertex2fv(v[d]);
        glEnd();
}

void Input1()
{
     glBegin(GL_POLYGON);
        glVertex2i(20+offsetx,540+offsety);
        glVertex2i(40+offsetx,540+offsety);
        glColor3f(0.219, 0.835, 0.960);
        glVertex2i(40+offsetx,580+offsety);
        glVertex2i(20+offsetx,580+offsety);
        glEnd();
}
void Input2()
{
     glBegin(GL_POLYGON);
        glVertex2i(20+offsetx,420+offsety);
        glVertex2i(40+offsetx,420+offsety);
        glColor3f(0.964, 0.905, 0.054);
        glVertex2i(40+offsetx,460+offsety);
        glVertex2i(20+offsetx,460+offsety);
        glEnd();
}
void Line(int a,int b)
{
    glBegin(GL_LINES);
    glVertex2fv(l[a]);
    glVertex2fv(l[b]);
    glEnd();
}
void display1()
{
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,1,1);
        print(340,900,"CMR INSTITUTE OF TECHNOLOGY");
        glColor3f(0.043, 0.466, 0.694);
        print(240,860,"#132, AECS LAYOUT, IT PARK ROAD, KUNDALAHALLI,");
        print(400,840,"BANGALORE-560037");
        print(240,800,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
        print(380,720,"A  Mini Project on");
        glColor3f(1,1,1);
        print(360,700,"\"Router Architecture\"");
        glColor3f(0.043, 0.466, 0.694);
        print(30,600,"Submitted in Partial fulfillment of the Requirements for the VI Semester of");
        print(420,580,"the Degree of");
        print(370,540,"Bachelor of Engineering");
        print(490,520,"In");
        print(320,500,"Computer Science & Engineering");
        print(490,480,"By");
        glColor3f(1,1,1);
        print(460,420,"DIVYA T");
        print(425,400,"(1CR15CS058)");
        print(420,320,"DHANUSH KUMAR S");
        print(425,300,"(1CR15CS055)");
        glColor3f(0.043, 0.466, 0.694);
        print(370,200,"Under the Guidance of");
        glColor3f(1,1,1);
        print(420,160,"Kiran Babu T S");
        glColor3f(0.043, 0.466, 0.694);
        print(320,140,"Assistant Professor,Dept of CSE");
        print(200,100,"(Click left mouse button to go to the next window)");
        print(310,50,"(Click right mouse button to exit)");
        glFlush();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glColor3f(0,1,0);                   //Router
    glLineWidth(2);
    OutLine(0,1,2,3);
    print(445,520,"Switching");
    print(455,490,"Fabric");

    glColor3f(0.956, 0.062, 0.105);                 //Boxes next to the router
    polygon(4,5,6,7);         //Right Bottom
    glColor3f(0.356, 0.913, 0.266);
    polygon(8,9,10,11);        //Right Top
    glColor3f(0.964, 0.905, 0.054);
    polygon(12,13,14,15);       //Left Bottom
    glColor3f(0.219, 0.835, 0.960);
    polygon(16,17,18,19);       //Left Top
    glColor3f(0,0,0);
    print(80,620,"Input port");
    print(20,560,"A");
    print(700,620,"Output port");
    print(960,560,"C");

    glLineWidth(1);
    glColor3f(1,1,1);                   //Output ports
    polygon(20,21,22,23);
    OutLine(20,21,22,23);
    glColor3f(1,1,1);
    polygon(24,25,26,27);
    OutLine(24,25,26,27);
    glColor3f(1,1,1);
    polygon(28,29,30,31);
    OutLine(28,29,30,31);
    glColor3f(1,1,1);
    polygon(32,33,34,35);
    OutLine(32,33,34,35);
    glColor3f(1,1,1);
    polygon(36,37,38,39);
    OutLine(36,37,38,39);
    glColor3f(1,1,1);
    polygon(40,41,42,43);
    OutLine(40,41,42,43);
    print(80,500,"Input port");
    print(20,430,"B");
    print(700,500,"Output port");
    print(960,430,"D");

    glColor3f(1,1,1);
    polygon(44,45,46,47);                   //Input ports
    OutLine(44,45,46,47);
    glColor3f(1,1,1);
    polygon(48,49,50,51);
    OutLine(48,49,50,51);
    glColor3f(1,1,1);
    polygon(52,53,54,55);
    OutLine(52,53,54,55);
    glColor3f(1,1,1);
    polygon(56,57,58,59);
    OutLine(56,57,58,59);
    glColor3f(1,1,1);
    polygon(60,61,62,63);
    OutLine(60,61,62,63);
    glColor3f(1,1,1);
    polygon(64,65,66,67);
    OutLine(64,65,66,67);

    glColor3f(0.964, 0.054, 0.549);
    polygon(68,69,70,71);
    OutLine(68,69,70,71);           //Routing Processor
    print(400,900,"Routing Processor");
    glPushAttrib(GL_ENABLE_BIT);
    glLineStipple(1, 0x0f0f);
    glEnable(GL_LINE_STIPPLE);
    Line(0,1);
    Line(2,3);
    Line(4,5);
    Line(6,7);
    glPushAttrib(GL_ENABLE_BIT);
    glLineStipple(1, 0xffff);
    glEnable(GL_LINE_STIPPLE);
    Line(8,9);
    Line(10,11);
    Line(12,13);
    Line(14,15);
    Line(16,17);
    Line(18,19);
    Line(20,21);
    Line(22,23);
    Line(24,25);
    print(20,800,"Routing, management");
    print(20,780,"control plane");
    print(19,760,"(software)");
    print(20,720,"Forwarding" );
    print(20,700,"data plane(hardware)");
    print(440,300,"Output Ports");
    print(360,200,"A");
    print(270,180,"Input");
    print(270,160,"Ports");
    print(360,140,"B");
    print(420,260,"C");
    print(480,260,"D");
    print(540,270,"Routing");
    print(540,250,"Processor");
    print(420,200,"m");
    print(480,200,"n");
    print(420,140,"b");
    print(480,140,"v");
    print(580,200,"c");
    print(580,140,"x");

    glColor3f(0.086, 0.662, 0.831);
    arrow();
    if(flag==1&& color==0){
        glColor3f(0.356, 0.913, 0.266);
        Input1();
    }
    if(flag==1&& color==1){
        glColor3f(0.956, 0.062, 0.105);
        Input1();
    }
    if(flag==1&& color==2){
        glColor3f(0.964, 0.054, 0.549);
        Input1();
    }
    if(flag==2&& color==0){
        glColor3f(0.356, 0.913, 0.266);
         Input2();
    }
     if(flag==2&& color==1){
        glColor3f(0.956, 0.062, 0.105);
        Input2();
    }
    if(flag==2&& color==2){
        glColor3f(0.964, 0.054, 0.549);
        Input2();
    }
     glColor3f(0,0,0);
     print(200,50,"(Click Right mouse button to exit and go to Home page)");
    glFlush();
}

void key(unsigned char key,int x0,int y0)
{
    if(key=='m')
    {
        flag=1;
        color=0;
        for(offsetx=20;offsetx<940;offsetx++)
           display();
        offsetx=0;
    }
    if(key=='n')
    {
        flag=1;
        color=1;
        for(offsetx=20;offsetx<460;offsetx++)
            display();
        for(offsety=0;offsety>-120;offsety--)
            display();
        for(offsetx=460;offsetx<940;offsetx++)
            display();
        offsetx=0;
        offsety=0;
    }
    if(key=='b'){
            flag=2;
        color=0;
        for(offsetx=20;offsetx<460;offsetx++)
            display();
        for(offsety=0;offsety<120;offsety++)
            display();
        for(offsetx=460;offsetx<940;offsetx++)
            display();
        offsetx=0;
        offsety=0;
    }
    if(key=='v')
    {
         flag=2;
        color=1;
        for(offsetx=20;offsetx<940;offsetx++)
           display();
        offsetx=0;
    }

    if(key=='c')
    {
        flag=1;
        color=2;
        for(offsetx=20;offsetx<250;offsetx++)
            display();
        for(offsety=0;offsety<275;offsety++)
            display();
        for(offsetx=250;offsetx<470;offsetx++)
            display();
        offsetx=0;
        offsety=0;
    }
    if(key=='x')
    {
        flag=2;
        color=2;
        for(offsetx=20;offsetx<250;offsetx++)
            display();
        for(offsety=0;offsety<395;offsety++)
            display();
        for(offsetx=250;offsetx<470;offsetx++)
            display();
        offsetx=0;
        offsety=0;
    }
}

void mouse1(int button,int state,int x,int y){
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
        glutDestroyWindow(displayscreen2);
}

void mouse(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        glutInitWindowSize(640,640);
        glutInitWindowPosition(0,0);
        glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
        displayscreen2=glutCreateWindow("Router Architecture");
        glEnable(GL_LINE_SMOOTH);
        glutReshapeFunc(init);
        glutMouseFunc(mouse1);
        glutKeyboardFunc(key);
        glutDisplayFunc(display);
        glClearColor(0,0,0,0);
        glutMainLoop();
    }
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
        glutDestroyWindow(displayscreen1);
}

/* Program entry point */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    displayscreen1=glutCreateWindow("Home Page");
    glEnable(GL_LINE_SMOOTH);
    glutReshapeFunc(init);
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glutDisplayFunc(display1);
    glClearColor(0,0,0,0);
    glutMainLoop();
}
