//
//  main.cpp
//  OpenGLTest
//
//  Created by 王天亮 on 2020/7/6.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
#include <GLShaderManager.h>
#include <GLTools.h> //工具类
#include <GLUT/GLUT.h> //mac下GLUT   windows/linux freeGlut

GLShaderManager shaderManager;
GLBatch triangleBatch;

//第一次运行会调用
//窗口大小发生改变

void changeSize(int w,int h)
{
    glViewport(0, 0, w, h);
}
GLfloat xPos = 0.0;
GLfloat yPos = 0.0;
GLfloat blockSize = 0.1;
GLfloat vVerts[] = {
    -blockSize, -blockSize, 0.0,
    blockSize, -blockSize, 0.0,
    blockSize, blockSize, 0.0,
    -blockSize, blockSize, 0.0
};

//渲染
void RenderScene(void)
{
    //清空颜色缓存区
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    GLfloat vRed[] = {0.0,1.0,0.0,1.0};
//    //单元 着色器
//    shaderManager.UseStockShader(GLT_SHADER_IDENTITY,vRed);
//    x,y,z,w缩放因子(1.0)
 //   四行四列矩阵
    M3DMatrix44f mTransFromMatrix, mfinalTransform, mRotationMatix;
    //平移  存放的地方/
//    m3dTranslationMatrix44(mTransFromMatrix, xPos, yPos, 0.0f);

    static float ZRot = 0.0;
    ZRot += 5.0;
    m3dRotationMatrix44(mRotationMatix, m3dDegToRad(ZRot), 0.0, 0.0, 1.0);
    //矩阵相乘
    m3dMatrixMultiply44(mfinalTransform, mfinalTransform, mRotationMatix);
    //平面着色器
    shaderManager.UseStockShader(GLT_SHADER_FLAT, mfinalTransform, vRed);
    //提交
    triangleBatch.Draw();
    
    glutSwapBuffers();
}
void setupRC() {
    //清空颜色缓存区 红/绿/蓝/透明度
    glClearColor(0.5f, 0.40f, 0.7f, 1);
    //管理着色器/初始化固定着色器
    shaderManager.InitializeStockShaders();
    //指定定点
//    GLfloat vVerts[] = {
//        0.0f,0.0f,0.0f,   //x, y, z
//        0.5f,0.5f,0.0f,
//        0.5f,0.0f,0.0f,
//        0.0f,0.5f,0.0f
//    };
    //用不同的模式来绘图
    //primitive
    //有几个顶点
    triangleBatch.Begin(GL_TRIANGLE_FAN, 4);
    triangleBatch.CopyVertexData3f(vVerts);
    triangleBatch.End();
}
void specialKey(int key, int x, int y) {
    //第一种方法
//    GLfloat stepSize = 0.02f;
//    //D点
//    GLfloat blockX = vVerts[0];
//    GLfloat blockY = vVerts[10];
//    //上下移动
//    if (key == GLUT_KEY_UP) {
//        blockY += stepSize;
//    }
//    if (key == GLUT_KEY_DOWN) {
//        blockY -= stepSize;
//    }
//    if (key == GLUT_KEY_LEFT) {
//        blockX -= stepSize;
//    }
//    if (key == GLUT_KEY_RIGHT) {
//        blockX += stepSize;
//    }
//    //更新其他顶点位置
//    //A点：
//    vVerts[0] = blockX;
//    vVerts[1] = blockY - blockSize * 2;
//    //B点：
//    vVerts[3] = blockX + 2 * blockSize;
//    vVerts[4] = blockY - 2 * blockSize;
//    //C点:
//    vVerts[6] = blockX + 2 * blockSize;
//    vVerts[7] = blockY;
//    //D点:
//    vVerts[9] = blockX;
//    vVerts[10] = blockY;
//    triangleBatch.CopyVertexData3f(vVerts);
//    glutPostRedisplay();
    //第二种代码
    GLfloat stepSize = 0.025;
    if (key == GLUT_KEY_UP) {
        yPos += stepSize;
    }
    if (key == GLUT_KEY_DOWN) {
        yPos -= stepSize;
    }
    if (key == GLUT_KEY_LEFT) {
        xPos -= stepSize;
    }
    if (key == GLUT_KEY_RIGHT) {
        xPos += stepSize;
    }
//    triangleBatch.CopyVertexData3f(vVerts);
    //边界检测
//    if (xPos < -1.0f + blockSize) {
//        xPos = -1.0f + blockSize;
//    }
//    if (xPos > 1.0f - blockSize) {
//        xPos = 1.0f - blockSize;
//    }
//    if (yPos < -1.0f + blockSize) {
//        yPos = -1.0f + blockSize;
//    }
//    if (yPos > 1.0f - blockSize) {
//        yPos = 1.0f -   blockSize;
//    }
    glutPostRedisplay();
     
}
int main(int argc,char *argv[])
{
    //设置当前工作目录
    gltSetWorkingDirectory(argv[0]);
    //初始化GLUT库
    glutInit(&argc, argv);
    //需要用到的颜色
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
    //初始化窗口大小
    glutInitWindowSize(800, 600);
    //窗口名字
    glutCreateWindow("Triangle");
    //尺寸改变调用这个函数
    glutReshapeFunc(changeSize);
    //显示的时候调用的函数
    glutDisplayFunc(RenderScene);
    //特殊建位置
    glutSpecialFunc(specialKey);
    
    GLenum status = glewInit();
    if (GLEW_OK != status) {
        printf("GLEW Error:%s\n",glewGetErrorString(status));
        return 1;
    }
    setupRC();
    glutMainLoop();
    return  0;
}
