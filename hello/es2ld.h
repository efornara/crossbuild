/*
  es2ld.h
  Written by Emanuele Fornara

  This is free and unencumbered software released into the public domain.

  Anyone is free to copy, modify, publish, use, compile, sell, or
  distribute this software, either in source code form or as a compiled
  binary, for any purpose, commercial or non-commercial, and by any
  means.

  In jurisdictions that recognize copyright laws, the author or authors
  of this software dedicate any and all copyright interest in the
  software to the public domain. We make this dedication for the benefit
  of the public at large and to the detriment of our heirs and
  successors. We intend this dedication to be an overt act of
  relinquishment in perpetuity of all present and future rights to this
  software under copyright law.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  OTHER DEALINGS IN THE SOFTWARE.

  For more information, please refer to <http://unlicense.org/>
 */

#ifndef ES2LD_H
#define ES2LD_H

#include <GLES2/gl2.h>

typedef void *(*ES2_FN_GetProcAddress)(const char *name);
extern void es2_init(ES2_FN_GetProcAddress get_proc_address, int is_es2_);
extern int is_es2;

typedef void (*ES2_FN_glActiveTexture)(GLenum texture);
typedef void (*ES2_FN_glAttachShader)(GLuint program, GLuint shader);
typedef void (*ES2_FN_glBindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
typedef void (*ES2_FN_glBindBuffer)(GLenum target, GLuint buffer);
typedef void (*ES2_FN_glBindFramebuffer)(GLenum target, GLuint framebuffer);
typedef void (*ES2_FN_glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
typedef void (*ES2_FN_glBindTexture)(GLenum target, GLuint texture);
typedef void (*ES2_FN_glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (*ES2_FN_glBlendEquation)(GLenum mode);
typedef void (*ES2_FN_glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
typedef void (*ES2_FN_glBlendFunc)(GLenum sfactor, GLenum dfactor);
typedef void (*ES2_FN_glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (*ES2_FN_glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (*ES2_FN_glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef GLenum (*ES2_FN_glCheckFramebufferStatus)(GLenum target);
typedef void (*ES2_FN_glClear)(GLbitfield mask);
typedef void (*ES2_FN_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (*ES2_FN_glClearDepthf)(GLfloat d);
typedef void (*ES2_FN_glClearStencil)(GLint s);
typedef void (*ES2_FN_glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (*ES2_FN_glCompileShader)(GLuint shader);
typedef void (*ES2_FN_glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (*ES2_FN_glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (*ES2_FN_glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (*ES2_FN_glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef GLuint (*ES2_FN_glCreateProgram)();
typedef GLuint (*ES2_FN_glCreateShader)(GLenum type);
typedef void (*ES2_FN_glCullFace)(GLenum mode);
typedef void (*ES2_FN_glDeleteBuffers)(GLsizei n, const GLuint *buffers);
typedef void (*ES2_FN_glDeleteFramebuffers)(GLsizei n, const GLuint *framebuffers);
typedef void (*ES2_FN_glDeleteProgram)(GLuint program);
typedef void (*ES2_FN_glDeleteRenderbuffers)(GLsizei n, const GLuint *renderbuffers);
typedef void (*ES2_FN_glDeleteShader)(GLuint shader);
typedef void (*ES2_FN_glDeleteTextures)(GLsizei n, const GLuint *textures);
typedef void (*ES2_FN_glDepthFunc)(GLenum func);
typedef void (*ES2_FN_glDepthMask)(GLboolean flag);
typedef void (*ES2_FN_glDepthRangef)(GLfloat n, GLfloat f);
typedef void (*ES2_FN_glDetachShader)(GLuint program, GLuint shader);
typedef void (*ES2_FN_glDisable)(GLenum cap);
typedef void (*ES2_FN_glDisableVertexAttribArray)(GLuint index);
typedef void (*ES2_FN_glDrawArrays)(GLenum mode, GLint first, GLsizei count);
typedef void (*ES2_FN_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (*ES2_FN_glEnable)(GLenum cap);
typedef void (*ES2_FN_glEnableVertexAttribArray)(GLuint index);
typedef void (*ES2_FN_glFinish)();
typedef void (*ES2_FN_glFlush)();
typedef void (*ES2_FN_glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (*ES2_FN_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (*ES2_FN_glFrontFace)(GLenum mode);
typedef void (*ES2_FN_glGenBuffers)(GLsizei n, GLuint *buffers);
typedef void (*ES2_FN_glGenerateMipmap)(GLenum target);
typedef void (*ES2_FN_glGenFramebuffers)(GLsizei n, GLuint *framebuffers);
typedef void (*ES2_FN_glGenRenderbuffers)(GLsizei n, GLuint *renderbuffers);
typedef void (*ES2_FN_glGenTextures)(GLsizei n, GLuint *textures);
typedef void (*ES2_FN_glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (*ES2_FN_glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (*ES2_FN_glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef GLint (*ES2_FN_glGetAttribLocation)(GLuint program, const GLchar *name);
typedef void (*ES2_FN_glGetBooleanv)(GLenum pname, GLboolean *data);
typedef void (*ES2_FN_glGetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
typedef GLenum (*ES2_FN_glGetError)();
typedef void (*ES2_FN_glGetFloatv)(GLenum pname, GLfloat *data);
typedef void (*ES2_FN_glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
typedef void (*ES2_FN_glGetIntegerv)(GLenum pname, GLint *data);
typedef void (*ES2_FN_glGetProgramiv)(GLuint program, GLenum pname, GLint *params);
typedef void (*ES2_FN_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (*ES2_FN_glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint *params);
typedef void (*ES2_FN_glGetShaderiv)(GLuint shader, GLenum pname, GLint *params);
typedef void (*ES2_FN_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (*ES2_FN_glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
typedef void (*ES2_FN_glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef const GLubyte * (*ES2_FN_glGetString)(GLenum name);
typedef void (*ES2_FN_glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
typedef void (*ES2_FN_glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
typedef void (*ES2_FN_glGetUniformfv)(GLuint program, GLint location, GLfloat *params);
typedef void (*ES2_FN_glGetUniformiv)(GLuint program, GLint location, GLint *params);
typedef GLint (*ES2_FN_glGetUniformLocation)(GLuint program, const GLchar *name);
typedef void (*ES2_FN_glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
typedef void (*ES2_FN_glGetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
typedef void (*ES2_FN_glGetVertexAttribPointerv)(GLuint index, GLenum pname, void **pointer);
typedef void (*ES2_FN_glHint)(GLenum target, GLenum mode);
typedef GLboolean (*ES2_FN_glIsBuffer)(GLuint buffer);
typedef GLboolean (*ES2_FN_glIsEnabled)(GLenum cap);
typedef GLboolean (*ES2_FN_glIsFramebuffer)(GLuint framebuffer);
typedef GLboolean (*ES2_FN_glIsProgram)(GLuint program);
typedef GLboolean (*ES2_FN_glIsRenderbuffer)(GLuint renderbuffer);
typedef GLboolean (*ES2_FN_glIsShader)(GLuint shader);
typedef GLboolean (*ES2_FN_glIsTexture)(GLuint texture);
typedef void (*ES2_FN_glLineWidth)(GLfloat width);
typedef void (*ES2_FN_glLinkProgram)(GLuint program);
typedef void (*ES2_FN_glPixelStorei)(GLenum pname, GLint param);
typedef void (*ES2_FN_glPolygonOffset)(GLfloat factor, GLfloat units);
typedef void (*ES2_FN_glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef void (*ES2_FN_glReleaseShaderCompiler)();
typedef void (*ES2_FN_glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (*ES2_FN_glSampleCoverage)(GLfloat value, GLboolean invert);
typedef void (*ES2_FN_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (*ES2_FN_glShaderBinary)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
typedef void (*ES2_FN_glShaderSource)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (*ES2_FN_glStencilFunc)(GLenum func, GLint ref, GLuint mask);
typedef void (*ES2_FN_glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (*ES2_FN_glStencilMask)(GLuint mask);
typedef void (*ES2_FN_glStencilMaskSeparate)(GLenum face, GLuint mask);
typedef void (*ES2_FN_glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
typedef void (*ES2_FN_glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (*ES2_FN_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (*ES2_FN_glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
typedef void (*ES2_FN_glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (*ES2_FN_glTexParameteri)(GLenum target, GLenum pname, GLint param);
typedef void (*ES2_FN_glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
typedef void (*ES2_FN_glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (*ES2_FN_glUniform1f)(GLint location, GLfloat v0);
typedef void (*ES2_FN_glUniform1fv)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*ES2_FN_glUniform1i)(GLint location, GLint v0);
typedef void (*ES2_FN_glUniform1iv)(GLint location, GLsizei count, const GLint *value);
typedef void (*ES2_FN_glUniform2f)(GLint location, GLfloat v0, GLfloat v1);
typedef void (*ES2_FN_glUniform2fv)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*ES2_FN_glUniform2i)(GLint location, GLint v0, GLint v1);
typedef void (*ES2_FN_glUniform2iv)(GLint location, GLsizei count, const GLint *value);
typedef void (*ES2_FN_glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (*ES2_FN_glUniform3fv)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*ES2_FN_glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (*ES2_FN_glUniform3iv)(GLint location, GLsizei count, const GLint *value);
typedef void (*ES2_FN_glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (*ES2_FN_glUniform4fv)(GLint location, GLsizei count, const GLfloat *value);
typedef void (*ES2_FN_glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (*ES2_FN_glUniform4iv)(GLint location, GLsizei count, const GLint *value);
typedef void (*ES2_FN_glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*ES2_FN_glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*ES2_FN_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (*ES2_FN_glUseProgram)(GLuint program);
typedef void (*ES2_FN_glValidateProgram)(GLuint program);
typedef void (*ES2_FN_glVertexAttrib1f)(GLuint index, GLfloat x);
typedef void (*ES2_FN_glVertexAttrib1fv)(GLuint index, const GLfloat *v);
typedef void (*ES2_FN_glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
typedef void (*ES2_FN_glVertexAttrib2fv)(GLuint index, const GLfloat *v);
typedef void (*ES2_FN_glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (*ES2_FN_glVertexAttrib3fv)(GLuint index, const GLfloat *v);
typedef void (*ES2_FN_glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (*ES2_FN_glVertexAttrib4fv)(GLuint index, const GLfloat *v);
typedef void (*ES2_FN_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
typedef void (*ES2_FN_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (*ES2_FN_glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);

#define glActiveTexture es2_fn_glActiveTexture
#define glAttachShader es2_fn_glAttachShader
#define glBindAttribLocation es2_fn_glBindAttribLocation
#define glBindBuffer es2_fn_glBindBuffer
#define glBindFramebuffer es2_fn_glBindFramebuffer
#define glBindRenderbuffer es2_fn_glBindRenderbuffer
#define glBindTexture es2_fn_glBindTexture
#define glBlendColor es2_fn_glBlendColor
#define glBlendEquation es2_fn_glBlendEquation
#define glBlendEquationSeparate es2_fn_glBlendEquationSeparate
#define glBlendFunc es2_fn_glBlendFunc
#define glBlendFuncSeparate es2_fn_glBlendFuncSeparate
#define glBufferData es2_fn_glBufferData
#define glBufferSubData es2_fn_glBufferSubData
#define glCheckFramebufferStatus es2_fn_glCheckFramebufferStatus
#define glClear es2_fn_glClear
#define glClearColor es2_fn_glClearColor
#define glClearDepthf es2_fn_glClearDepthf
#define glClearStencil es2_fn_glClearStencil
#define glColorMask es2_fn_glColorMask
#define glCompileShader es2_fn_glCompileShader
#define glCompressedTexImage2D es2_fn_glCompressedTexImage2D
#define glCompressedTexSubImage2D es2_fn_glCompressedTexSubImage2D
#define glCopyTexImage2D es2_fn_glCopyTexImage2D
#define glCopyTexSubImage2D es2_fn_glCopyTexSubImage2D
#define glCreateProgram es2_fn_glCreateProgram
#define glCreateShader es2_fn_glCreateShader
#define glCullFace es2_fn_glCullFace
#define glDeleteBuffers es2_fn_glDeleteBuffers
#define glDeleteFramebuffers es2_fn_glDeleteFramebuffers
#define glDeleteProgram es2_fn_glDeleteProgram
#define glDeleteRenderbuffers es2_fn_glDeleteRenderbuffers
#define glDeleteShader es2_fn_glDeleteShader
#define glDeleteTextures es2_fn_glDeleteTextures
#define glDepthFunc es2_fn_glDepthFunc
#define glDepthMask es2_fn_glDepthMask
#define glDepthRangef es2_fn_glDepthRangef
#define glDetachShader es2_fn_glDetachShader
#define glDisable es2_fn_glDisable
#define glDisableVertexAttribArray es2_fn_glDisableVertexAttribArray
#define glDrawArrays es2_fn_glDrawArrays
#define glDrawElements es2_fn_glDrawElements
#define glEnable es2_fn_glEnable
#define glEnableVertexAttribArray es2_fn_glEnableVertexAttribArray
#define glFinish es2_fn_glFinish
#define glFlush es2_fn_glFlush
#define glFramebufferRenderbuffer es2_fn_glFramebufferRenderbuffer
#define glFramebufferTexture2D es2_fn_glFramebufferTexture2D
#define glFrontFace es2_fn_glFrontFace
#define glGenBuffers es2_fn_glGenBuffers
#define glGenerateMipmap es2_fn_glGenerateMipmap
#define glGenFramebuffers es2_fn_glGenFramebuffers
#define glGenRenderbuffers es2_fn_glGenRenderbuffers
#define glGenTextures es2_fn_glGenTextures
#define glGetActiveAttrib es2_fn_glGetActiveAttrib
#define glGetActiveUniform es2_fn_glGetActiveUniform
#define glGetAttachedShaders es2_fn_glGetAttachedShaders
#define glGetAttribLocation es2_fn_glGetAttribLocation
#define glGetBooleanv es2_fn_glGetBooleanv
#define glGetBufferParameteriv es2_fn_glGetBufferParameteriv
#define glGetError es2_fn_glGetError
#define glGetFloatv es2_fn_glGetFloatv
#define glGetFramebufferAttachmentParameteriv es2_fn_glGetFramebufferAttachmentParameteriv
#define glGetIntegerv es2_fn_glGetIntegerv
#define glGetProgramiv es2_fn_glGetProgramiv
#define glGetProgramInfoLog es2_fn_glGetProgramInfoLog
#define glGetRenderbufferParameteriv es2_fn_glGetRenderbufferParameteriv
#define glGetShaderiv es2_fn_glGetShaderiv
#define glGetShaderInfoLog es2_fn_glGetShaderInfoLog
#define glGetShaderPrecisionFormat es2_fn_glGetShaderPrecisionFormat
#define glGetShaderSource es2_fn_glGetShaderSource
#define glGetString es2_fn_glGetString
#define glGetTexParameterfv es2_fn_glGetTexParameterfv
#define glGetTexParameteriv es2_fn_glGetTexParameteriv
#define glGetUniformfv es2_fn_glGetUniformfv
#define glGetUniformiv es2_fn_glGetUniformiv
#define glGetUniformLocation es2_fn_glGetUniformLocation
#define glGetVertexAttribfv es2_fn_glGetVertexAttribfv
#define glGetVertexAttribiv es2_fn_glGetVertexAttribiv
#define glGetVertexAttribPointerv es2_fn_glGetVertexAttribPointerv
#define glHint es2_fn_glHint
#define glIsBuffer es2_fn_glIsBuffer
#define glIsEnabled es2_fn_glIsEnabled
#define glIsFramebuffer es2_fn_glIsFramebuffer
#define glIsProgram es2_fn_glIsProgram
#define glIsRenderbuffer es2_fn_glIsRenderbuffer
#define glIsShader es2_fn_glIsShader
#define glIsTexture es2_fn_glIsTexture
#define glLineWidth es2_fn_glLineWidth
#define glLinkProgram es2_fn_glLinkProgram
#define glPixelStorei es2_fn_glPixelStorei
#define glPolygonOffset es2_fn_glPolygonOffset
#define glReadPixels es2_fn_glReadPixels
#define glReleaseShaderCompiler es2_fn_glReleaseShaderCompiler
#define glRenderbufferStorage es2_fn_glRenderbufferStorage
#define glSampleCoverage es2_fn_glSampleCoverage
#define glScissor es2_fn_glScissor
#define glShaderBinary es2_fn_glShaderBinary
#define glShaderSource es2_fn_glShaderSource
#define glStencilFunc es2_fn_glStencilFunc
#define glStencilFuncSeparate es2_fn_glStencilFuncSeparate
#define glStencilMask es2_fn_glStencilMask
#define glStencilMaskSeparate es2_fn_glStencilMaskSeparate
#define glStencilOp es2_fn_glStencilOp
#define glStencilOpSeparate es2_fn_glStencilOpSeparate
#define glTexImage2D es2_fn_glTexImage2D
#define glTexParameterf es2_fn_glTexParameterf
#define glTexParameterfv es2_fn_glTexParameterfv
#define glTexParameteri es2_fn_glTexParameteri
#define glTexParameteriv es2_fn_glTexParameteriv
#define glTexSubImage2D es2_fn_glTexSubImage2D
#define glUniform1f es2_fn_glUniform1f
#define glUniform1fv es2_fn_glUniform1fv
#define glUniform1i es2_fn_glUniform1i
#define glUniform1iv es2_fn_glUniform1iv
#define glUniform2f es2_fn_glUniform2f
#define glUniform2fv es2_fn_glUniform2fv
#define glUniform2i es2_fn_glUniform2i
#define glUniform2iv es2_fn_glUniform2iv
#define glUniform3f es2_fn_glUniform3f
#define glUniform3fv es2_fn_glUniform3fv
#define glUniform3i es2_fn_glUniform3i
#define glUniform3iv es2_fn_glUniform3iv
#define glUniform4f es2_fn_glUniform4f
#define glUniform4fv es2_fn_glUniform4fv
#define glUniform4i es2_fn_glUniform4i
#define glUniform4iv es2_fn_glUniform4iv
#define glUniformMatrix2fv es2_fn_glUniformMatrix2fv
#define glUniformMatrix3fv es2_fn_glUniformMatrix3fv
#define glUniformMatrix4fv es2_fn_glUniformMatrix4fv
#define glUseProgram es2_fn_glUseProgram
#define glValidateProgram es2_fn_glValidateProgram
#define glVertexAttrib1f es2_fn_glVertexAttrib1f
#define glVertexAttrib1fv es2_fn_glVertexAttrib1fv
#define glVertexAttrib2f es2_fn_glVertexAttrib2f
#define glVertexAttrib2fv es2_fn_glVertexAttrib2fv
#define glVertexAttrib3f es2_fn_glVertexAttrib3f
#define glVertexAttrib3fv es2_fn_glVertexAttrib3fv
#define glVertexAttrib4f es2_fn_glVertexAttrib4f
#define glVertexAttrib4fv es2_fn_glVertexAttrib4fv
#define glVertexAttribPointer es2_fn_glVertexAttribPointer
#define glViewport es2_fn_glViewport
#define glRenderbufferStorageMultisample es2_fn_glRenderbufferStorageMultisample

extern ES2_FN_glActiveTexture es2_fn_glActiveTexture;
extern ES2_FN_glAttachShader es2_fn_glAttachShader;
extern ES2_FN_glBindAttribLocation es2_fn_glBindAttribLocation;
extern ES2_FN_glBindBuffer es2_fn_glBindBuffer;
extern ES2_FN_glBindFramebuffer es2_fn_glBindFramebuffer;
extern ES2_FN_glBindRenderbuffer es2_fn_glBindRenderbuffer;
extern ES2_FN_glBindTexture es2_fn_glBindTexture;
extern ES2_FN_glBlendColor es2_fn_glBlendColor;
extern ES2_FN_glBlendEquation es2_fn_glBlendEquation;
extern ES2_FN_glBlendEquationSeparate es2_fn_glBlendEquationSeparate;
extern ES2_FN_glBlendFunc es2_fn_glBlendFunc;
extern ES2_FN_glBlendFuncSeparate es2_fn_glBlendFuncSeparate;
extern ES2_FN_glBufferData es2_fn_glBufferData;
extern ES2_FN_glBufferSubData es2_fn_glBufferSubData;
extern ES2_FN_glCheckFramebufferStatus es2_fn_glCheckFramebufferStatus;
extern ES2_FN_glClear es2_fn_glClear;
extern ES2_FN_glClearColor es2_fn_glClearColor;
extern ES2_FN_glClearDepthf es2_fn_glClearDepthf;
extern ES2_FN_glClearStencil es2_fn_glClearStencil;
extern ES2_FN_glColorMask es2_fn_glColorMask;
extern ES2_FN_glCompileShader es2_fn_glCompileShader;
extern ES2_FN_glCompressedTexImage2D es2_fn_glCompressedTexImage2D;
extern ES2_FN_glCompressedTexSubImage2D es2_fn_glCompressedTexSubImage2D;
extern ES2_FN_glCopyTexImage2D es2_fn_glCopyTexImage2D;
extern ES2_FN_glCopyTexSubImage2D es2_fn_glCopyTexSubImage2D;
extern ES2_FN_glCreateProgram es2_fn_glCreateProgram;
extern ES2_FN_glCreateShader es2_fn_glCreateShader;
extern ES2_FN_glCullFace es2_fn_glCullFace;
extern ES2_FN_glDeleteBuffers es2_fn_glDeleteBuffers;
extern ES2_FN_glDeleteFramebuffers es2_fn_glDeleteFramebuffers;
extern ES2_FN_glDeleteProgram es2_fn_glDeleteProgram;
extern ES2_FN_glDeleteRenderbuffers es2_fn_glDeleteRenderbuffers;
extern ES2_FN_glDeleteShader es2_fn_glDeleteShader;
extern ES2_FN_glDeleteTextures es2_fn_glDeleteTextures;
extern ES2_FN_glDepthFunc es2_fn_glDepthFunc;
extern ES2_FN_glDepthMask es2_fn_glDepthMask;
extern ES2_FN_glDepthRangef es2_fn_glDepthRangef;
extern ES2_FN_glDetachShader es2_fn_glDetachShader;
extern ES2_FN_glDisable es2_fn_glDisable;
extern ES2_FN_glDisableVertexAttribArray es2_fn_glDisableVertexAttribArray;
extern ES2_FN_glDrawArrays es2_fn_glDrawArrays;
extern ES2_FN_glDrawElements es2_fn_glDrawElements;
extern ES2_FN_glEnable es2_fn_glEnable;
extern ES2_FN_glEnableVertexAttribArray es2_fn_glEnableVertexAttribArray;
extern ES2_FN_glFinish es2_fn_glFinish;
extern ES2_FN_glFlush es2_fn_glFlush;
extern ES2_FN_glFramebufferRenderbuffer es2_fn_glFramebufferRenderbuffer;
extern ES2_FN_glFramebufferTexture2D es2_fn_glFramebufferTexture2D;
extern ES2_FN_glFrontFace es2_fn_glFrontFace;
extern ES2_FN_glGenBuffers es2_fn_glGenBuffers;
extern ES2_FN_glGenerateMipmap es2_fn_glGenerateMipmap;
extern ES2_FN_glGenFramebuffers es2_fn_glGenFramebuffers;
extern ES2_FN_glGenRenderbuffers es2_fn_glGenRenderbuffers;
extern ES2_FN_glGenTextures es2_fn_glGenTextures;
extern ES2_FN_glGetActiveAttrib es2_fn_glGetActiveAttrib;
extern ES2_FN_glGetActiveUniform es2_fn_glGetActiveUniform;
extern ES2_FN_glGetAttachedShaders es2_fn_glGetAttachedShaders;
extern ES2_FN_glGetAttribLocation es2_fn_glGetAttribLocation;
extern ES2_FN_glGetBooleanv es2_fn_glGetBooleanv;
extern ES2_FN_glGetBufferParameteriv es2_fn_glGetBufferParameteriv;
extern ES2_FN_glGetError es2_fn_glGetError;
extern ES2_FN_glGetFloatv es2_fn_glGetFloatv;
extern ES2_FN_glGetFramebufferAttachmentParameteriv es2_fn_glGetFramebufferAttachmentParameteriv;
extern ES2_FN_glGetIntegerv es2_fn_glGetIntegerv;
extern ES2_FN_glGetProgramiv es2_fn_glGetProgramiv;
extern ES2_FN_glGetProgramInfoLog es2_fn_glGetProgramInfoLog;
extern ES2_FN_glGetRenderbufferParameteriv es2_fn_glGetRenderbufferParameteriv;
extern ES2_FN_glGetShaderiv es2_fn_glGetShaderiv;
extern ES2_FN_glGetShaderInfoLog es2_fn_glGetShaderInfoLog;
extern ES2_FN_glGetShaderPrecisionFormat es2_fn_glGetShaderPrecisionFormat;
extern ES2_FN_glGetShaderSource es2_fn_glGetShaderSource;
extern ES2_FN_glGetString es2_fn_glGetString;
extern ES2_FN_glGetTexParameterfv es2_fn_glGetTexParameterfv;
extern ES2_FN_glGetTexParameteriv es2_fn_glGetTexParameteriv;
extern ES2_FN_glGetUniformfv es2_fn_glGetUniformfv;
extern ES2_FN_glGetUniformiv es2_fn_glGetUniformiv;
extern ES2_FN_glGetUniformLocation es2_fn_glGetUniformLocation;
extern ES2_FN_glGetVertexAttribfv es2_fn_glGetVertexAttribfv;
extern ES2_FN_glGetVertexAttribiv es2_fn_glGetVertexAttribiv;
extern ES2_FN_glGetVertexAttribPointerv es2_fn_glGetVertexAttribPointerv;
extern ES2_FN_glHint es2_fn_glHint;
extern ES2_FN_glIsBuffer es2_fn_glIsBuffer;
extern ES2_FN_glIsEnabled es2_fn_glIsEnabled;
extern ES2_FN_glIsFramebuffer es2_fn_glIsFramebuffer;
extern ES2_FN_glIsProgram es2_fn_glIsProgram;
extern ES2_FN_glIsRenderbuffer es2_fn_glIsRenderbuffer;
extern ES2_FN_glIsShader es2_fn_glIsShader;
extern ES2_FN_glIsTexture es2_fn_glIsTexture;
extern ES2_FN_glLineWidth es2_fn_glLineWidth;
extern ES2_FN_glLinkProgram es2_fn_glLinkProgram;
extern ES2_FN_glPixelStorei es2_fn_glPixelStorei;
extern ES2_FN_glPolygonOffset es2_fn_glPolygonOffset;
extern ES2_FN_glReadPixels es2_fn_glReadPixels;
extern ES2_FN_glReleaseShaderCompiler es2_fn_glReleaseShaderCompiler;
extern ES2_FN_glRenderbufferStorage es2_fn_glRenderbufferStorage;
extern ES2_FN_glSampleCoverage es2_fn_glSampleCoverage;
extern ES2_FN_glScissor es2_fn_glScissor;
extern ES2_FN_glShaderBinary es2_fn_glShaderBinary;
extern ES2_FN_glShaderSource es2_fn_glShaderSource;
extern ES2_FN_glStencilFunc es2_fn_glStencilFunc;
extern ES2_FN_glStencilFuncSeparate es2_fn_glStencilFuncSeparate;
extern ES2_FN_glStencilMask es2_fn_glStencilMask;
extern ES2_FN_glStencilMaskSeparate es2_fn_glStencilMaskSeparate;
extern ES2_FN_glStencilOp es2_fn_glStencilOp;
extern ES2_FN_glStencilOpSeparate es2_fn_glStencilOpSeparate;
extern ES2_FN_glTexImage2D es2_fn_glTexImage2D;
extern ES2_FN_glTexParameterf es2_fn_glTexParameterf;
extern ES2_FN_glTexParameterfv es2_fn_glTexParameterfv;
extern ES2_FN_glTexParameteri es2_fn_glTexParameteri;
extern ES2_FN_glTexParameteriv es2_fn_glTexParameteriv;
extern ES2_FN_glTexSubImage2D es2_fn_glTexSubImage2D;
extern ES2_FN_glUniform1f es2_fn_glUniform1f;
extern ES2_FN_glUniform1fv es2_fn_glUniform1fv;
extern ES2_FN_glUniform1i es2_fn_glUniform1i;
extern ES2_FN_glUniform1iv es2_fn_glUniform1iv;
extern ES2_FN_glUniform2f es2_fn_glUniform2f;
extern ES2_FN_glUniform2fv es2_fn_glUniform2fv;
extern ES2_FN_glUniform2i es2_fn_glUniform2i;
extern ES2_FN_glUniform2iv es2_fn_glUniform2iv;
extern ES2_FN_glUniform3f es2_fn_glUniform3f;
extern ES2_FN_glUniform3fv es2_fn_glUniform3fv;
extern ES2_FN_glUniform3i es2_fn_glUniform3i;
extern ES2_FN_glUniform3iv es2_fn_glUniform3iv;
extern ES2_FN_glUniform4f es2_fn_glUniform4f;
extern ES2_FN_glUniform4fv es2_fn_glUniform4fv;
extern ES2_FN_glUniform4i es2_fn_glUniform4i;
extern ES2_FN_glUniform4iv es2_fn_glUniform4iv;
extern ES2_FN_glUniformMatrix2fv es2_fn_glUniformMatrix2fv;
extern ES2_FN_glUniformMatrix3fv es2_fn_glUniformMatrix3fv;
extern ES2_FN_glUniformMatrix4fv es2_fn_glUniformMatrix4fv;
extern ES2_FN_glUseProgram es2_fn_glUseProgram;
extern ES2_FN_glValidateProgram es2_fn_glValidateProgram;
extern ES2_FN_glVertexAttrib1f es2_fn_glVertexAttrib1f;
extern ES2_FN_glVertexAttrib1fv es2_fn_glVertexAttrib1fv;
extern ES2_FN_glVertexAttrib2f es2_fn_glVertexAttrib2f;
extern ES2_FN_glVertexAttrib2fv es2_fn_glVertexAttrib2fv;
extern ES2_FN_glVertexAttrib3f es2_fn_glVertexAttrib3f;
extern ES2_FN_glVertexAttrib3fv es2_fn_glVertexAttrib3fv;
extern ES2_FN_glVertexAttrib4f es2_fn_glVertexAttrib4f;
extern ES2_FN_glVertexAttrib4fv es2_fn_glVertexAttrib4fv;
extern ES2_FN_glVertexAttribPointer es2_fn_glVertexAttribPointer;
extern ES2_FN_glViewport es2_fn_glViewport;
extern ES2_FN_glRenderbufferStorageMultisample es2_fn_glRenderbufferStorageMultisample;

#endif /* ES2LD_H */
