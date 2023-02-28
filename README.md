## GDDR6(X) GPU Memory Temperature reader for linux


## Needs:
- libpciaccess-dev and libpci-dev 
```
sudo apt install libpciaccess-dev libpci-dev -y
```

- Kernel boot parameter: iomem=relaxed
```
sudo vim /etc/default/grub
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash iomem=relaxed"
sudo update-grub
sudo reboot
```

## Support
- RTX 4090 (AD102)
- RTX 3080 (GA102)
- RTX 3070 (GA104)

![](https://github.com/olealgoritme/gddr6/blob/master/gddr6_use.gif)
