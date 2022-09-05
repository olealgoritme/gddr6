#ifndef CGEN_GPU_H
#define CGEN_GPU_H
#include <stdbool.h>
#include <stdint.h>
#include "bus.h"
#include "fb.h"

enum gpu_gen_index {
	GEN_NV1,
	GEN_NV3,
	GEN_NV4,
	GEN_CELSIUS,
	GEN_KELVIN,
	GEN_RANKINE,
	GEN_CURIE,
	GEN_TESLA,
	GEN_FERMI,
	GEN_KEPLER,
	GEN_MAXWELL,
	GEN_PASCAL,
	GEN_VOLTA,
	GEN_TURING,
	NUM_GPU_GEN,
	GPU_GEN_UNKNOWN = NUM_GPU_GEN,
};

enum gpu_index {
	GPU_NV1,
	GPU_NV3,
	GPU_NV3T,
	GPU_NV4,
	GPU_NV5,
	GPU_NV6,
	GPU_NVA,
	GPU_NV10,
	GPU_NV15,
	GPU_NV1A,
	GPU_NV11,
	GPU_NV17,
	GPU_NV1F,
	GPU_NV18,
	GPU_NV20,
	GPU_NV2A,
	GPU_NV25,
	GPU_NV28,
	GPU_NV30,
	GPU_NV35,
	GPU_NV31,
	GPU_NV36,
	GPU_NV34,
	GPU_NV40,
	GPU_NV45,
	GPU_NV41,
	GPU_NV42,
	GPU_NV43,
	GPU_NV44,
	GPU_NV44A,
	GPU_G70,
	GPU_G72,
	GPU_G71,
	GPU_G73,
	GPU_C51,
	GPU_MCP61,
	GPU_MCP67,
	GPU_MCP68,
	GPU_MCP73,
	GPU_RSX,
	GPU_G80,
	GPU_G84,
	GPU_G86,
	GPU_G92,
	GPU_G94,
	GPU_G96,
	GPU_G98,
	GPU_G200,
	GPU_MCP77,
	GPU_MCP79,
	GPU_GT215,
	GPU_GT216,
	GPU_GT218,
	GPU_MCP89,
	GPU_GF100,
	GPU_GF104,
	GPU_GF114,
	GPU_GF106,
	GPU_GF116,
	GPU_GF108,
	GPU_GF110,
	GPU_GF119,
	GPU_GF117,
	GPU_GK104,
	GPU_GK107,
	GPU_GK106,
	GPU_GK110,
	GPU_GK110B,
	GPU_GK210,
	GPU_GK208,
	GPU_GK208B,
	GPU_GK20A,
	GPU_GM107,
	GPU_GM108,
	GPU_GM204,
	GPU_GM200,
	GPU_GM206,
	GPU_GM20B,
	GPU_GP100,
	GPU_GP102,
	GPU_GP104,
	GPU_GP106,
	GPU_GP107,
	GPU_GP108,
	GPU_GP10B,
	GPU_GV100,
	GPU_GV11B,
	GPU_TU102,
	GPU_TU104,
	GPU_TU106,
	GPU_TU116,
	GPU_TU117,
	NUM_GPU,
	GPU_UNKNOWN = NUM_GPU,
};

extern const struct gpu {
	const char *name;
	uint32_t id;
	bool id_valid;
	uint32_t pciid;
	bool pciid_valid;
	int pciid_varbits;
	bool pciid_varbits_valid;
	uint32_t bios_major;
	bool bios_major_valid;
	uint32_t bios_chip;
	bool bios_chip_valid;
	enum bus_interface_index bus;
	enum fb_gen_index fb;
	enum gpu_gen_index gen;
} gpu_list[];

#endif


