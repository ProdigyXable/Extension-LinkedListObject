#pragma once

// #define TGFEXT       // TGF2, MMF2, MMF2 Dev
   #define MMFEXT       // MMF2, MMF2 Dev
// #define PROEXT       // MMF2 Dev only

#include    "Edif.h"
#include	"Resource.h"

// edPtr : Used at edittime and saved in the MFA/CCN/EXE files

struct EDITDATA
{
	// Header - required
	extHeader		eHeader;

	// Object's data
//	short			swidth;
//	short			sheight;

};

#define NewNode 1
#define RemovedNode 2
#define ListCleared 3
#define IndexError 4

#include "Extension.h"


