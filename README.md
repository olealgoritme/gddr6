## GDDR6/GDDR6X GPU Memory Temperature Reader for Linux

Reads GDDR6/GDDR6X VRAM memory temperatures from multiple supported NVIDIA GPUs found in a host Linux system.
These findings are based on reverse engineering of the NVIDIA GPU Linux driver.

### Experimental: RTX 5090 (GDDR7)

Experimental support for the RTX 5090 (Blackwell / GB202, GDDR7) is included. It reads the per-module
DRAM sensors directly and reports the hotspot (hottest module) by default:

```
sudo gddr6                # VRAM hotspot temperature
sudo gddr6 --per-module   # each of the 8 GDDR7 modules separately
```

This is reverse-engineered and unofficial (NVIDIA does not expose memory temperature via nvidia-smi/NVML
on this card) — treat the readings as approximate.

For a dedicated Blackwell app with a TUI (plus ASCII/JSON output) and a reusable C library, see
[**gpuwatch**](https://github.com/olealgoritme/gpuwatch).


## Prerequisites

- Kernel boot parameter: iomem=relaxed

This step is optional. In some Linux distributions, the default kernel boot parameters are sufficient to run this program.

```
sudo vim /etc/default/grub
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash iomem=relaxed"
sudo update-grub
sudo reboot
```

- Disabling Secure Boot
  
This can be done in the UEFI/BIOS configuration or using [mokutil](https://wiki.debian.org/SecureBoot#Disabling.2Fre-enabling_Secure_Boot):

```
mokutil --disable-validation
```

Check state with:
```
$ sudo mokutil --sb
SecureBoot disabled
```

## Dependencies
- libpci-dev 
```
sudo apt install libpci-dev -y
```

## Installation (cmake)
```
git clone https://github.com/olealgoritme/gddr6
cd gddr6
./build_install.sh
sudo gddr6
```

## Supported GPUs
- RTX 5090 (GB202) — GDDR7, experimental (see above)
- RTX 4090 (AD102)
- RTX 4080 Super (AD103)
- RTX 4080 (AD103)
- RTX 4070 Ti Super (AD103)
- RTX 4070 Ti (AD104)
- RTX 4070 Super (AD104)
- RTX 4070 (AD104)
- RTX 4060 Max-Q / Mobile (AD107)
- RTX 3090 Ti (GA102)
- RTX 3090 (GA102)
- RTX 3080 Ti (GA102)
- RTX 3080 (GA102)
- RTX 3080 LHR (GA102)
- RTX 3070 (GA104)
- RTX 3070 LHR (GA104)
- RTX A2000 (GA106)
- RTX A4500 (GA102)
- RTX A5000 (GA102)
- RTX A6000 (AD102)
- L4 (AD104)
- L40S (AD102)
- A10 (GA102)

![](https://github.com/olealgoritme/gddr6/blob/master/gddr6_use.gif)
