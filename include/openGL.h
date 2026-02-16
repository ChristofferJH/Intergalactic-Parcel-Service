#ifndef OPENGL_H
#define OPENGL_H

#include "core.h"
#include "import/openGLImport.h"

#define LOAD_GL_FUNCTION(type, name)\
name = (type)wglGetProcAddress(#name);

#define LOAD_GL_FUNCTION_EXTENDED(type, localname, extensionName)\
localname = (type)wglGetProcAddress(#extensionName);

void LoadOpenGLFunctions();

//context creation
extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
extern PFNWGLSWAPINTERVALEXTPROC glSwapInterval;

//shaders & shader programs
extern PFNGLCREATESHADERPROC glCreateShader;
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
extern PFNGLUSEPROGRAMPROC glUseProgram;
extern PFNGLLINKPROGRAMPROC glLinkProgram;
extern PFNGLATTACHSHADERPROC glAttachShader;
extern PFNGLSHADERSOURCEPROC glShaderSource;
extern PFNGLCOMPILESHADERPROC glCompileShader;
extern PFNGLDELETESHADERPROC glDeleteShader;
extern PFNGLDELETEPROGRAMPROC glDeleteProgram;

#endif