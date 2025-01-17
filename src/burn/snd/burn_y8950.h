#include "driver.h"
extern "C" {
 #include "fmopl.h"
}
#include "timer.h"

INT32 BurnY8950Init(INT32 num, INT32 nClockFrequency, UINT8* Y8950ADPCM0ROM, INT32 nY8950ADPCM0Size, UINT8* Y8950ADPCM1ROM, INT32 nY8950ADPCM1Size, OPL_IRQHANDLER IRQCallback, INT32 (*StreamCallback)(INT32), INT32 bAddSignal);
void BurnY8950SetRoute(INT32 nChip, INT32 nIndex, double nVolume, INT32 nRouteDir);
void BurnY8950Reset();
void BurnY8950Exit();
extern void (*BurnY8950Update)(INT16* pSoundBuf, INT32 nSegmentEnd);
void BurnY8950Scan(INT32 nAction, INT32* pnMin);

#define BURN_SND_Y8950_ROUTE			0

#define BurnY8950Read(i, a) Y8950Read(i, a)

#if defined FBNEO_DEBUG
	#define BurnY8950Write(i, a, n) if (!DebugSnd_Y8950Initted) bprintf(PRINT_ERROR, _T("BurnY8950Write called without init\n")); Y8950Write(i, a, n)
#else
	#define BurnY8950Write(i, a, n) Y8950Write(i, a, n)
#endif
