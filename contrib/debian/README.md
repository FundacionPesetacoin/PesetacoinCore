
Debian
====================
This directory contains files used to package pesetacoind/pesetacoin-qt
for Debian-based Linux systems. If you compile pesetacoind/pesetacoin-qt yourself, there are some useful files here.

## pesetacoin: URI support ##


pesetacoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install pesetacoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your pesetacoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/pesetacoin128.png` to `/usr/share/pixmaps`

pesetacoin-qt.protocol (KDE)

