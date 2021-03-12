#pragma once

#include "ClassIDs.h"

#define		REGISTER_DERIVED_CLASS(x, d) \
public: \
	/*virtual int GetClassIDVirtualInternal () const; */\
	static int GetClassIDStatic ()				{ return ClassID (x); } \
	static const char* GetClassStringStatic (){ return #x; }			\
	static bool IsAbstract() { return false; } \
	/*static Object* PRODUCE (MemLabelId label, ObjectCreationMode mode)	{ return UNITY_NEW_AS_ROOT( x (label, mode), label, NULL, NULL); } */\
	/*static const char* GetPPtrTypeString ()	 { return "PPtr<"#x">"; }	*/\
	typedef d Super; \
	static void RegisterClass (); \
	public: \
	~x (); \
	public:


// Every abstract class that is derived from object has to place this inside the class Declaration
// (REGISTER_DERIVED_ABSTRACT_CLASS (Foo, Object))
#define		REGISTER_DERIVED_ABSTRACT_CLASS(x, d) \
	public: \
	/*virtual int GetClassIDVirtualInternal () const; */\
	static int GetClassIDStatic ()				{ return ClassID (x); } \
	static const char* GetClassStringStatic() { return #x; }			\
	static bool IsAbstract ()						{ return true; }\
	/*static Object* PRODUCE (MemLabelId, ObjectCreationMode)						{ AssertString ("Can't produce abstract class"); return NULL; } */\
	/*static const char* GetPPtrTypeString ()	 { return "PPtr<"#x">"; }	*/\
	typedef d Super; \
	static void RegisterClass (); \
	protected: \
	~x (); \
	public: