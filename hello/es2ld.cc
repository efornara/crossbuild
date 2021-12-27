/*
  es2ld.cc
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

#include "es2ld.h"

int is_es2 = 0;

ES2_FN_glActiveTexture es2_fn_glActiveTexture = 0;
ES2_FN_glAttachShader es2_fn_glAttachShader = 0;
ES2_FN_glBindAttribLocation es2_fn_glBindAttribLocation = 0;
ES2_FN_glBindBuffer es2_fn_glBindBuffer = 0;
ES2_FN_glBindFramebuffer es2_fn_glBindFramebuffer = 0;
ES2_FN_glBindRenderbuffer es2_fn_glBindRenderbuffer = 0;
ES2_FN_glBindTexture es2_fn_glBindTexture = 0;
ES2_FN_glBlendColor es2_fn_glBlendColor = 0;
ES2_FN_glBlendEquation es2_fn_glBlendEquation = 0;
ES2_FN_glBlendEquationSeparate es2_fn_glBlendEquationSeparate = 0;
ES2_FN_glBlendFunc es2_fn_glBlendFunc = 0;
ES2_FN_glBlendFuncSeparate es2_fn_glBlendFuncSeparate = 0;
ES2_FN_glBufferData es2_fn_glBufferData = 0;
ES2_FN_glBufferSubData es2_fn_glBufferSubData = 0;
ES2_FN_glCheckFramebufferStatus es2_fn_glCheckFramebufferStatus = 0;
ES2_FN_glClear es2_fn_glClear = 0;
ES2_FN_glClearColor es2_fn_glClearColor = 0;
ES2_FN_glClearDepthf es2_fn_glClearDepthf = 0;
ES2_FN_glClearStencil es2_fn_glClearStencil = 0;
ES2_FN_glColorMask es2_fn_glColorMask = 0;
ES2_FN_glCompileShader es2_fn_glCompileShader = 0;
ES2_FN_glCompressedTexImage2D es2_fn_glCompressedTexImage2D = 0;
ES2_FN_glCompressedTexSubImage2D es2_fn_glCompressedTexSubImage2D = 0;
ES2_FN_glCopyTexImage2D es2_fn_glCopyTexImage2D = 0;
ES2_FN_glCopyTexSubImage2D es2_fn_glCopyTexSubImage2D = 0;
ES2_FN_glCreateProgram es2_fn_glCreateProgram = 0;
ES2_FN_glCreateShader es2_fn_glCreateShader = 0;
ES2_FN_glCullFace es2_fn_glCullFace = 0;
ES2_FN_glDeleteBuffers es2_fn_glDeleteBuffers = 0;
ES2_FN_glDeleteFramebuffers es2_fn_glDeleteFramebuffers = 0;
ES2_FN_glDeleteProgram es2_fn_glDeleteProgram = 0;
ES2_FN_glDeleteRenderbuffers es2_fn_glDeleteRenderbuffers = 0;
ES2_FN_glDeleteShader es2_fn_glDeleteShader = 0;
ES2_FN_glDeleteTextures es2_fn_glDeleteTextures = 0;
ES2_FN_glDepthFunc es2_fn_glDepthFunc = 0;
ES2_FN_glDepthMask es2_fn_glDepthMask = 0;
ES2_FN_glDepthRangef es2_fn_glDepthRangef = 0;
ES2_FN_glDetachShader es2_fn_glDetachShader = 0;
ES2_FN_glDisable es2_fn_glDisable = 0;
ES2_FN_glDisableVertexAttribArray es2_fn_glDisableVertexAttribArray = 0;
ES2_FN_glDrawArrays es2_fn_glDrawArrays = 0;
ES2_FN_glDrawElements es2_fn_glDrawElements = 0;
ES2_FN_glEnable es2_fn_glEnable = 0;
ES2_FN_glEnableVertexAttribArray es2_fn_glEnableVertexAttribArray = 0;
ES2_FN_glFinish es2_fn_glFinish = 0;
ES2_FN_glFlush es2_fn_glFlush = 0;
ES2_FN_glFramebufferRenderbuffer es2_fn_glFramebufferRenderbuffer = 0;
ES2_FN_glFramebufferTexture2D es2_fn_glFramebufferTexture2D = 0;
ES2_FN_glFrontFace es2_fn_glFrontFace = 0;
ES2_FN_glGenBuffers es2_fn_glGenBuffers = 0;
ES2_FN_glGenerateMipmap es2_fn_glGenerateMipmap = 0;
ES2_FN_glGenFramebuffers es2_fn_glGenFramebuffers = 0;
ES2_FN_glGenRenderbuffers es2_fn_glGenRenderbuffers = 0;
ES2_FN_glGenTextures es2_fn_glGenTextures = 0;
ES2_FN_glGetActiveAttrib es2_fn_glGetActiveAttrib = 0;
ES2_FN_glGetActiveUniform es2_fn_glGetActiveUniform = 0;
ES2_FN_glGetAttachedShaders es2_fn_glGetAttachedShaders = 0;
ES2_FN_glGetAttribLocation es2_fn_glGetAttribLocation = 0;
ES2_FN_glGetBooleanv es2_fn_glGetBooleanv = 0;
ES2_FN_glGetBufferParameteriv es2_fn_glGetBufferParameteriv = 0;
ES2_FN_glGetError es2_fn_glGetError = 0;
ES2_FN_glGetFloatv es2_fn_glGetFloatv = 0;
ES2_FN_glGetFramebufferAttachmentParameteriv es2_fn_glGetFramebufferAttachmentParameteriv = 0;
ES2_FN_glGetIntegerv es2_fn_glGetIntegerv = 0;
ES2_FN_glGetProgramiv es2_fn_glGetProgramiv = 0;
ES2_FN_glGetProgramInfoLog es2_fn_glGetProgramInfoLog = 0;
ES2_FN_glGetRenderbufferParameteriv es2_fn_glGetRenderbufferParameteriv = 0;
ES2_FN_glGetShaderiv es2_fn_glGetShaderiv = 0;
ES2_FN_glGetShaderInfoLog es2_fn_glGetShaderInfoLog = 0;
ES2_FN_glGetShaderPrecisionFormat es2_fn_glGetShaderPrecisionFormat = 0;
ES2_FN_glGetShaderSource es2_fn_glGetShaderSource = 0;
ES2_FN_glGetString es2_fn_glGetString = 0;
ES2_FN_glGetTexParameterfv es2_fn_glGetTexParameterfv = 0;
ES2_FN_glGetTexParameteriv es2_fn_glGetTexParameteriv = 0;
ES2_FN_glGetUniformfv es2_fn_glGetUniformfv = 0;
ES2_FN_glGetUniformiv es2_fn_glGetUniformiv = 0;
ES2_FN_glGetUniformLocation es2_fn_glGetUniformLocation = 0;
ES2_FN_glGetVertexAttribfv es2_fn_glGetVertexAttribfv = 0;
ES2_FN_glGetVertexAttribiv es2_fn_glGetVertexAttribiv = 0;
ES2_FN_glGetVertexAttribPointerv es2_fn_glGetVertexAttribPointerv = 0;
ES2_FN_glHint es2_fn_glHint = 0;
ES2_FN_glIsBuffer es2_fn_glIsBuffer = 0;
ES2_FN_glIsEnabled es2_fn_glIsEnabled = 0;
ES2_FN_glIsFramebuffer es2_fn_glIsFramebuffer = 0;
ES2_FN_glIsProgram es2_fn_glIsProgram = 0;
ES2_FN_glIsRenderbuffer es2_fn_glIsRenderbuffer = 0;
ES2_FN_glIsShader es2_fn_glIsShader = 0;
ES2_FN_glIsTexture es2_fn_glIsTexture = 0;
ES2_FN_glLineWidth es2_fn_glLineWidth = 0;
ES2_FN_glLinkProgram es2_fn_glLinkProgram = 0;
ES2_FN_glPixelStorei es2_fn_glPixelStorei = 0;
ES2_FN_glPolygonOffset es2_fn_glPolygonOffset = 0;
ES2_FN_glReadPixels es2_fn_glReadPixels = 0;
ES2_FN_glReleaseShaderCompiler es2_fn_glReleaseShaderCompiler = 0;
ES2_FN_glRenderbufferStorage es2_fn_glRenderbufferStorage = 0;
ES2_FN_glSampleCoverage es2_fn_glSampleCoverage = 0;
ES2_FN_glScissor es2_fn_glScissor = 0;
ES2_FN_glShaderBinary es2_fn_glShaderBinary = 0;
ES2_FN_glShaderSource es2_fn_glShaderSource = 0;
ES2_FN_glStencilFunc es2_fn_glStencilFunc = 0;
ES2_FN_glStencilFuncSeparate es2_fn_glStencilFuncSeparate = 0;
ES2_FN_glStencilMask es2_fn_glStencilMask = 0;
ES2_FN_glStencilMaskSeparate es2_fn_glStencilMaskSeparate = 0;
ES2_FN_glStencilOp es2_fn_glStencilOp = 0;
ES2_FN_glStencilOpSeparate es2_fn_glStencilOpSeparate = 0;
ES2_FN_glTexImage2D es2_fn_glTexImage2D = 0;
ES2_FN_glTexParameterf es2_fn_glTexParameterf = 0;
ES2_FN_glTexParameterfv es2_fn_glTexParameterfv = 0;
ES2_FN_glTexParameteri es2_fn_glTexParameteri = 0;
ES2_FN_glTexParameteriv es2_fn_glTexParameteriv = 0;
ES2_FN_glTexSubImage2D es2_fn_glTexSubImage2D = 0;
ES2_FN_glUniform1f es2_fn_glUniform1f = 0;
ES2_FN_glUniform1fv es2_fn_glUniform1fv = 0;
ES2_FN_glUniform1i es2_fn_glUniform1i = 0;
ES2_FN_glUniform1iv es2_fn_glUniform1iv = 0;
ES2_FN_glUniform2f es2_fn_glUniform2f = 0;
ES2_FN_glUniform2fv es2_fn_glUniform2fv = 0;
ES2_FN_glUniform2i es2_fn_glUniform2i = 0;
ES2_FN_glUniform2iv es2_fn_glUniform2iv = 0;
ES2_FN_glUniform3f es2_fn_glUniform3f = 0;
ES2_FN_glUniform3fv es2_fn_glUniform3fv = 0;
ES2_FN_glUniform3i es2_fn_glUniform3i = 0;
ES2_FN_glUniform3iv es2_fn_glUniform3iv = 0;
ES2_FN_glUniform4f es2_fn_glUniform4f = 0;
ES2_FN_glUniform4fv es2_fn_glUniform4fv = 0;
ES2_FN_glUniform4i es2_fn_glUniform4i = 0;
ES2_FN_glUniform4iv es2_fn_glUniform4iv = 0;
ES2_FN_glUniformMatrix2fv es2_fn_glUniformMatrix2fv = 0;
ES2_FN_glUniformMatrix3fv es2_fn_glUniformMatrix3fv = 0;
ES2_FN_glUniformMatrix4fv es2_fn_glUniformMatrix4fv = 0;
ES2_FN_glUseProgram es2_fn_glUseProgram = 0;
ES2_FN_glValidateProgram es2_fn_glValidateProgram = 0;
ES2_FN_glVertexAttrib1f es2_fn_glVertexAttrib1f = 0;
ES2_FN_glVertexAttrib1fv es2_fn_glVertexAttrib1fv = 0;
ES2_FN_glVertexAttrib2f es2_fn_glVertexAttrib2f = 0;
ES2_FN_glVertexAttrib2fv es2_fn_glVertexAttrib2fv = 0;
ES2_FN_glVertexAttrib3f es2_fn_glVertexAttrib3f = 0;
ES2_FN_glVertexAttrib3fv es2_fn_glVertexAttrib3fv = 0;
ES2_FN_glVertexAttrib4f es2_fn_glVertexAttrib4f = 0;
ES2_FN_glVertexAttrib4fv es2_fn_glVertexAttrib4fv = 0;
ES2_FN_glVertexAttribPointer es2_fn_glVertexAttribPointer = 0;
ES2_FN_glViewport es2_fn_glViewport = 0;
ES2_FN_glRenderbufferStorageMultisample es2_fn_glRenderbufferStorageMultisample = 0;

void es2_init(ES2_FN_GetProcAddress get_proc_address, int is_es2_) {
  is_es2 = is_es2_;
  es2_fn_glActiveTexture = (ES2_FN_glActiveTexture)get_proc_address("glActiveTexture");
  es2_fn_glAttachShader = (ES2_FN_glAttachShader)get_proc_address("glAttachShader");
  es2_fn_glBindAttribLocation = (ES2_FN_glBindAttribLocation)get_proc_address("glBindAttribLocation");
  es2_fn_glBindBuffer = (ES2_FN_glBindBuffer)get_proc_address("glBindBuffer");
  es2_fn_glBindFramebuffer = (ES2_FN_glBindFramebuffer)get_proc_address("glBindFramebuffer");
  es2_fn_glBindRenderbuffer = (ES2_FN_glBindRenderbuffer)get_proc_address("glBindRenderbuffer");
  es2_fn_glBindTexture = (ES2_FN_glBindTexture)get_proc_address("glBindTexture");
  es2_fn_glBlendColor = (ES2_FN_glBlendColor)get_proc_address("glBlendColor");
  es2_fn_glBlendEquation = (ES2_FN_glBlendEquation)get_proc_address("glBlendEquation");
  es2_fn_glBlendEquationSeparate = (ES2_FN_glBlendEquationSeparate)get_proc_address("glBlendEquationSeparate");
  es2_fn_glBlendFunc = (ES2_FN_glBlendFunc)get_proc_address("glBlendFunc");
  es2_fn_glBlendFuncSeparate = (ES2_FN_glBlendFuncSeparate)get_proc_address("glBlendFuncSeparate");
  es2_fn_glBufferData = (ES2_FN_glBufferData)get_proc_address("glBufferData");
  es2_fn_glBufferSubData = (ES2_FN_glBufferSubData)get_proc_address("glBufferSubData");
  es2_fn_glCheckFramebufferStatus = (ES2_FN_glCheckFramebufferStatus)get_proc_address("glCheckFramebufferStatus");
  es2_fn_glClear = (ES2_FN_glClear)get_proc_address("glClear");
  es2_fn_glClearColor = (ES2_FN_glClearColor)get_proc_address("glClearColor");
  es2_fn_glClearDepthf = (ES2_FN_glClearDepthf)get_proc_address("glClearDepthf");
  es2_fn_glClearStencil = (ES2_FN_glClearStencil)get_proc_address("glClearStencil");
  es2_fn_glColorMask = (ES2_FN_glColorMask)get_proc_address("glColorMask");
  es2_fn_glCompileShader = (ES2_FN_glCompileShader)get_proc_address("glCompileShader");
  es2_fn_glCompressedTexImage2D = (ES2_FN_glCompressedTexImage2D)get_proc_address("glCompressedTexImage2D");
  es2_fn_glCompressedTexSubImage2D = (ES2_FN_glCompressedTexSubImage2D)get_proc_address("glCompressedTexSubImage2D");
  es2_fn_glCopyTexImage2D = (ES2_FN_glCopyTexImage2D)get_proc_address("glCopyTexImage2D");
  es2_fn_glCopyTexSubImage2D = (ES2_FN_glCopyTexSubImage2D)get_proc_address("glCopyTexSubImage2D");
  es2_fn_glCreateProgram = (ES2_FN_glCreateProgram)get_proc_address("glCreateProgram");
  es2_fn_glCreateShader = (ES2_FN_glCreateShader)get_proc_address("glCreateShader");
  es2_fn_glCullFace = (ES2_FN_glCullFace)get_proc_address("glCullFace");
  es2_fn_glDeleteBuffers = (ES2_FN_glDeleteBuffers)get_proc_address("glDeleteBuffers");
  es2_fn_glDeleteFramebuffers = (ES2_FN_glDeleteFramebuffers)get_proc_address("glDeleteFramebuffers");
  es2_fn_glDeleteProgram = (ES2_FN_glDeleteProgram)get_proc_address("glDeleteProgram");
  es2_fn_glDeleteRenderbuffers = (ES2_FN_glDeleteRenderbuffers)get_proc_address("glDeleteRenderbuffers");
  es2_fn_glDeleteShader = (ES2_FN_glDeleteShader)get_proc_address("glDeleteShader");
  es2_fn_glDeleteTextures = (ES2_FN_glDeleteTextures)get_proc_address("glDeleteTextures");
  es2_fn_glDepthFunc = (ES2_FN_glDepthFunc)get_proc_address("glDepthFunc");
  es2_fn_glDepthMask = (ES2_FN_glDepthMask)get_proc_address("glDepthMask");
  es2_fn_glDepthRangef = (ES2_FN_glDepthRangef)get_proc_address("glDepthRangef");
  es2_fn_glDetachShader = (ES2_FN_glDetachShader)get_proc_address("glDetachShader");
  es2_fn_glDisable = (ES2_FN_glDisable)get_proc_address("glDisable");
  es2_fn_glDisableVertexAttribArray = (ES2_FN_glDisableVertexAttribArray)get_proc_address("glDisableVertexAttribArray");
  es2_fn_glDrawArrays = (ES2_FN_glDrawArrays)get_proc_address("glDrawArrays");
  es2_fn_glDrawElements = (ES2_FN_glDrawElements)get_proc_address("glDrawElements");
  es2_fn_glEnable = (ES2_FN_glEnable)get_proc_address("glEnable");
  es2_fn_glEnableVertexAttribArray = (ES2_FN_glEnableVertexAttribArray)get_proc_address("glEnableVertexAttribArray");
  es2_fn_glFinish = (ES2_FN_glFinish)get_proc_address("glFinish");
  es2_fn_glFlush = (ES2_FN_glFlush)get_proc_address("glFlush");
  es2_fn_glFramebufferRenderbuffer = (ES2_FN_glFramebufferRenderbuffer)get_proc_address("glFramebufferRenderbuffer");
  es2_fn_glFramebufferTexture2D = (ES2_FN_glFramebufferTexture2D)get_proc_address("glFramebufferTexture2D");
  es2_fn_glFrontFace = (ES2_FN_glFrontFace)get_proc_address("glFrontFace");
  es2_fn_glGenBuffers = (ES2_FN_glGenBuffers)get_proc_address("glGenBuffers");
  es2_fn_glGenerateMipmap = (ES2_FN_glGenerateMipmap)get_proc_address("glGenerateMipmap");
  es2_fn_glGenFramebuffers = (ES2_FN_glGenFramebuffers)get_proc_address("glGenFramebuffers");
  es2_fn_glGenRenderbuffers = (ES2_FN_glGenRenderbuffers)get_proc_address("glGenRenderbuffers");
  es2_fn_glGenTextures = (ES2_FN_glGenTextures)get_proc_address("glGenTextures");
  es2_fn_glGetActiveAttrib = (ES2_FN_glGetActiveAttrib)get_proc_address("glGetActiveAttrib");
  es2_fn_glGetActiveUniform = (ES2_FN_glGetActiveUniform)get_proc_address("glGetActiveUniform");
  es2_fn_glGetAttachedShaders = (ES2_FN_glGetAttachedShaders)get_proc_address("glGetAttachedShaders");
  es2_fn_glGetAttribLocation = (ES2_FN_glGetAttribLocation)get_proc_address("glGetAttribLocation");
  es2_fn_glGetBooleanv = (ES2_FN_glGetBooleanv)get_proc_address("glGetBooleanv");
  es2_fn_glGetBufferParameteriv = (ES2_FN_glGetBufferParameteriv)get_proc_address("glGetBufferParameteriv");
  es2_fn_glGetError = (ES2_FN_glGetError)get_proc_address("glGetError");
  es2_fn_glGetFloatv = (ES2_FN_glGetFloatv)get_proc_address("glGetFloatv");
  es2_fn_glGetFramebufferAttachmentParameteriv = (ES2_FN_glGetFramebufferAttachmentParameteriv)get_proc_address("glGetFramebufferAttachmentParameteriv");
  es2_fn_glGetIntegerv = (ES2_FN_glGetIntegerv)get_proc_address("glGetIntegerv");
  es2_fn_glGetProgramiv = (ES2_FN_glGetProgramiv)get_proc_address("glGetProgramiv");
  es2_fn_glGetProgramInfoLog = (ES2_FN_glGetProgramInfoLog)get_proc_address("glGetProgramInfoLog");
  es2_fn_glGetRenderbufferParameteriv = (ES2_FN_glGetRenderbufferParameteriv)get_proc_address("glGetRenderbufferParameteriv");
  es2_fn_glGetShaderiv = (ES2_FN_glGetShaderiv)get_proc_address("glGetShaderiv");
  es2_fn_glGetShaderInfoLog = (ES2_FN_glGetShaderInfoLog)get_proc_address("glGetShaderInfoLog");
  es2_fn_glGetShaderPrecisionFormat = (ES2_FN_glGetShaderPrecisionFormat)get_proc_address("glGetShaderPrecisionFormat");
  es2_fn_glGetShaderSource = (ES2_FN_glGetShaderSource)get_proc_address("glGetShaderSource");
  es2_fn_glGetString = (ES2_FN_glGetString)get_proc_address("glGetString");
  es2_fn_glGetTexParameterfv = (ES2_FN_glGetTexParameterfv)get_proc_address("glGetTexParameterfv");
  es2_fn_glGetTexParameteriv = (ES2_FN_glGetTexParameteriv)get_proc_address("glGetTexParameteriv");
  es2_fn_glGetUniformfv = (ES2_FN_glGetUniformfv)get_proc_address("glGetUniformfv");
  es2_fn_glGetUniformiv = (ES2_FN_glGetUniformiv)get_proc_address("glGetUniformiv");
  es2_fn_glGetUniformLocation = (ES2_FN_glGetUniformLocation)get_proc_address("glGetUniformLocation");
  es2_fn_glGetVertexAttribfv = (ES2_FN_glGetVertexAttribfv)get_proc_address("glGetVertexAttribfv");
  es2_fn_glGetVertexAttribiv = (ES2_FN_glGetVertexAttribiv)get_proc_address("glGetVertexAttribiv");
  es2_fn_glGetVertexAttribPointerv = (ES2_FN_glGetVertexAttribPointerv)get_proc_address("glGetVertexAttribPointerv");
  es2_fn_glHint = (ES2_FN_glHint)get_proc_address("glHint");
  es2_fn_glIsBuffer = (ES2_FN_glIsBuffer)get_proc_address("glIsBuffer");
  es2_fn_glIsEnabled = (ES2_FN_glIsEnabled)get_proc_address("glIsEnabled");
  es2_fn_glIsFramebuffer = (ES2_FN_glIsFramebuffer)get_proc_address("glIsFramebuffer");
  es2_fn_glIsProgram = (ES2_FN_glIsProgram)get_proc_address("glIsProgram");
  es2_fn_glIsRenderbuffer = (ES2_FN_glIsRenderbuffer)get_proc_address("glIsRenderbuffer");
  es2_fn_glIsShader = (ES2_FN_glIsShader)get_proc_address("glIsShader");
  es2_fn_glIsTexture = (ES2_FN_glIsTexture)get_proc_address("glIsTexture");
  es2_fn_glLineWidth = (ES2_FN_glLineWidth)get_proc_address("glLineWidth");
  es2_fn_glLinkProgram = (ES2_FN_glLinkProgram)get_proc_address("glLinkProgram");
  es2_fn_glPixelStorei = (ES2_FN_glPixelStorei)get_proc_address("glPixelStorei");
  es2_fn_glPolygonOffset = (ES2_FN_glPolygonOffset)get_proc_address("glPolygonOffset");
  es2_fn_glReadPixels = (ES2_FN_glReadPixels)get_proc_address("glReadPixels");
  es2_fn_glReleaseShaderCompiler = (ES2_FN_glReleaseShaderCompiler)get_proc_address("glReleaseShaderCompiler");
  es2_fn_glRenderbufferStorage = (ES2_FN_glRenderbufferStorage)get_proc_address("glRenderbufferStorage");
  es2_fn_glSampleCoverage = (ES2_FN_glSampleCoverage)get_proc_address("glSampleCoverage");
  es2_fn_glScissor = (ES2_FN_glScissor)get_proc_address("glScissor");
  es2_fn_glShaderBinary = (ES2_FN_glShaderBinary)get_proc_address("glShaderBinary");
  es2_fn_glShaderSource = (ES2_FN_glShaderSource)get_proc_address("glShaderSource");
  es2_fn_glStencilFunc = (ES2_FN_glStencilFunc)get_proc_address("glStencilFunc");
  es2_fn_glStencilFuncSeparate = (ES2_FN_glStencilFuncSeparate)get_proc_address("glStencilFuncSeparate");
  es2_fn_glStencilMask = (ES2_FN_glStencilMask)get_proc_address("glStencilMask");
  es2_fn_glStencilMaskSeparate = (ES2_FN_glStencilMaskSeparate)get_proc_address("glStencilMaskSeparate");
  es2_fn_glStencilOp = (ES2_FN_glStencilOp)get_proc_address("glStencilOp");
  es2_fn_glStencilOpSeparate = (ES2_FN_glStencilOpSeparate)get_proc_address("glStencilOpSeparate");
  es2_fn_glTexImage2D = (ES2_FN_glTexImage2D)get_proc_address("glTexImage2D");
  es2_fn_glTexParameterf = (ES2_FN_glTexParameterf)get_proc_address("glTexParameterf");
  es2_fn_glTexParameterfv = (ES2_FN_glTexParameterfv)get_proc_address("glTexParameterfv");
  es2_fn_glTexParameteri = (ES2_FN_glTexParameteri)get_proc_address("glTexParameteri");
  es2_fn_glTexParameteriv = (ES2_FN_glTexParameteriv)get_proc_address("glTexParameteriv");
  es2_fn_glTexSubImage2D = (ES2_FN_glTexSubImage2D)get_proc_address("glTexSubImage2D");
  es2_fn_glUniform1f = (ES2_FN_glUniform1f)get_proc_address("glUniform1f");
  es2_fn_glUniform1fv = (ES2_FN_glUniform1fv)get_proc_address("glUniform1fv");
  es2_fn_glUniform1i = (ES2_FN_glUniform1i)get_proc_address("glUniform1i");
  es2_fn_glUniform1iv = (ES2_FN_glUniform1iv)get_proc_address("glUniform1iv");
  es2_fn_glUniform2f = (ES2_FN_glUniform2f)get_proc_address("glUniform2f");
  es2_fn_glUniform2fv = (ES2_FN_glUniform2fv)get_proc_address("glUniform2fv");
  es2_fn_glUniform2i = (ES2_FN_glUniform2i)get_proc_address("glUniform2i");
  es2_fn_glUniform2iv = (ES2_FN_glUniform2iv)get_proc_address("glUniform2iv");
  es2_fn_glUniform3f = (ES2_FN_glUniform3f)get_proc_address("glUniform3f");
  es2_fn_glUniform3fv = (ES2_FN_glUniform3fv)get_proc_address("glUniform3fv");
  es2_fn_glUniform3i = (ES2_FN_glUniform3i)get_proc_address("glUniform3i");
  es2_fn_glUniform3iv = (ES2_FN_glUniform3iv)get_proc_address("glUniform3iv");
  es2_fn_glUniform4f = (ES2_FN_glUniform4f)get_proc_address("glUniform4f");
  es2_fn_glUniform4fv = (ES2_FN_glUniform4fv)get_proc_address("glUniform4fv");
  es2_fn_glUniform4i = (ES2_FN_glUniform4i)get_proc_address("glUniform4i");
  es2_fn_glUniform4iv = (ES2_FN_glUniform4iv)get_proc_address("glUniform4iv");
  es2_fn_glUniformMatrix2fv = (ES2_FN_glUniformMatrix2fv)get_proc_address("glUniformMatrix2fv");
  es2_fn_glUniformMatrix3fv = (ES2_FN_glUniformMatrix3fv)get_proc_address("glUniformMatrix3fv");
  es2_fn_glUniformMatrix4fv = (ES2_FN_glUniformMatrix4fv)get_proc_address("glUniformMatrix4fv");
  es2_fn_glUseProgram = (ES2_FN_glUseProgram)get_proc_address("glUseProgram");
  es2_fn_glValidateProgram = (ES2_FN_glValidateProgram)get_proc_address("glValidateProgram");
  es2_fn_glVertexAttrib1f = (ES2_FN_glVertexAttrib1f)get_proc_address("glVertexAttrib1f");
  es2_fn_glVertexAttrib1fv = (ES2_FN_glVertexAttrib1fv)get_proc_address("glVertexAttrib1fv");
  es2_fn_glVertexAttrib2f = (ES2_FN_glVertexAttrib2f)get_proc_address("glVertexAttrib2f");
  es2_fn_glVertexAttrib2fv = (ES2_FN_glVertexAttrib2fv)get_proc_address("glVertexAttrib2fv");
  es2_fn_glVertexAttrib3f = (ES2_FN_glVertexAttrib3f)get_proc_address("glVertexAttrib3f");
  es2_fn_glVertexAttrib3fv = (ES2_FN_glVertexAttrib3fv)get_proc_address("glVertexAttrib3fv");
  es2_fn_glVertexAttrib4f = (ES2_FN_glVertexAttrib4f)get_proc_address("glVertexAttrib4f");
  es2_fn_glVertexAttrib4fv = (ES2_FN_glVertexAttrib4fv)get_proc_address("glVertexAttrib4fv");
  es2_fn_glVertexAttribPointer = (ES2_FN_glVertexAttribPointer)get_proc_address("glVertexAttribPointer");
  es2_fn_glViewport = (ES2_FN_glViewport)get_proc_address("glViewport");
  es2_fn_glRenderbufferStorageMultisample = (ES2_FN_glRenderbufferStorageMultisample)get_proc_address("glRenderbufferStorageMultisample");
}
