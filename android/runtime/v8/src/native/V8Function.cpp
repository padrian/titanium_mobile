/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include <jni.h>
#include <v8.h>

#include "JNIUtil.h""
#include "TypeConverter.h"

#define TAG "V8Function"

using namespace titanium;

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     org_appcelerator_kroll_runtime_v8_V8Function
 * Method:    nativeInvoke
 * Signature: (JLjava/lang/Object)V
 */
JNIEXPORT void JNICALL Java_org_appcelerator_kroll_runtime_v8_V8Object_nativeInvoke(
	JNIEnv *env, jobject caller, jlong functionPointer, jobject functionArgument)
{
	titanium::JNIScope jniScope(env);
	HandleScope scope;

	// construct function from pointer
	v8::Handle<v8::Function> jsFunction((v8::Function *) functionPointer);

	// construct arguments array
	Handle<Value> functionArguments[] = { TypeConverter::javaObjectToJsValue(functionArgument) };

	// call into the JS function with the provided argument
	jsFunction->Call(jsFunction, 1, functionArgs);
}

#ifdef __cplusplus
}
#endif

