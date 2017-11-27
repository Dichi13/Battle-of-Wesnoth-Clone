#ifndef PLOT_H
#define PLOT_H

#include "boolean.h"
#include "point.h"
#include "unit.h"
#include "mesinkata.h"

#define Nil NULL

typedef struct Ptype{
	POINT Coordinate;	/* Koordinat Petak */
	char PlotType;		/* Jenis Petak, Tower = 'T', Castle = 'C', Village = 'V', Normal = 'N' */
	int Owner;			/* Kepemilikan Petak, 0 untuk tidak ada kepemilikan, 1 untuk player 1, dan 2 untuk player 2 */
	Unit* PlotUnit;		/* Pointer ke Unit yang ada di petak */
} Plot;

/* Selektor Petak */
#define Coordinate(PLOT) (PLOT).Coordinate
#define PlotType(PLOT) (PLOT).PlotType
#define Owner(PLOT) (PLOT).Owner
#define PlotUnit(PLOT) (PLOT).PlotUnit

#endif
