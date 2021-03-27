# Booten
Voor het booten heb ik geen extra boot-opties aangegeven. Ik heb een VM met een virtuele ethernetverbinding die voor internet zorgt, dus dat werk out-of-the-box. Daarna heb ik ssh opgestart omdat de terminal van de VM zeer traag is met text printen, dit vertraagt alle commands die veel text naar stdout gooien (zoals tar of emerge).

# De harde schijf
## Verschillen tussen MBR en GPT
MBR - Master Boot Record | GPT - GUID Partition Table
------------------------ | --------------------------
Maximaal 4 primary partities | Detectie voor datacorruptie
Max 2TB per partitie | In theorie oneindige partities

## Partitieschema
Het partitieschema ziet er als volgt uit:

![Partitieschema](https://cooledomeinnaam.nl/Partitieschema.png)

Ik heb het schema gemaakt met Parted en geen geadvanceerde opties gebruikt.

# Het basissysteem
Geen opmerkingen.

# Configuratie
## CFLAGS, CXXFLAGS en MAKEOPTS
> The CFLAGS and CXXFLAGS variables define the optimization flags for GCC C and C++ compilers respectively. Although those are defined generally here, for maximum performance one would need to optimize these flags for each program separately.

> The MAKEOPTS variable defines how many parallel compilations should occur when installing a package. A good choice is the number of CPUs (or CPU cores) in the system plus one, but this guideline isn't always perfect.

`MAKEOPTS="-j3"` in plaats van `"-j2"`. Dit omdat de VM 2 cores heeft en het is aangeraden om het aantal CPU's te nemen +1.

## @World
`@world` omvat de sets `@system` en `@selected`. `@system` is de set waar alle paketten in zitten die vereist zijn om het systeem te laten werken. `@selected` is de set waar alle paketten in zitten die de admin heeft geselecteerd.

Het updaten van `@world` op dit punt zorgt ervoor dat je een up-to-date systeem hebt om mee verder te werken.

## USE Variabele
`USE="acl amd64 berkdb bzip2 cli crypt cxx dri fortran gdbm iconv ipv6 libtirpc ncurses nls nptl openmp pam pcre readline seccomp ssl tcpd unicode xattr zlib"` is de default voor de `USE` variable. Ik heb `avahi zsh-completion` toegevoegd.
* `Avahi` is handig omdat ik dan bij het systeem kan komen met `ssh root@hostname.local` in plaats van `ssh root@ip.van.de.host`.
* `Zsh-completion` omdat ik een groot fan ben van zsh en dat ga installeren zodra we zover zijn, en auto-completion kan ik waarderen.

## Kernel Configuratie
De opties die ik heb gekozen zijn de defaults van [het handboek](https://wiki.gentoo.org/wiki/Handbook:AMD64/Full/Installation#Activating_required_options) en de opties om het beter te laten werken met de virtualisatiesoftware [QEMU](https://wiki.gentoo.org/wiki/QEMU/Linux_guest).

## fstab
Bevat de volgende regels:

![fstab](https://cooledomeinnaam.nl/fstab.png)

## rc-update en init-scripts
`rc-update` volgens hun man-page:
> OpenRC uses named runlevels.  Rather than editing some obscure file or managing a directory of symlinks, rc-update exists to quickly add or delete services to and from from different runlevels. All services must reside in the /etc/init.d or /usr/local/etc/init.d directories.  They must also be standard OpenRC scripts, meaning they must use openrc-run.

`init-scripts` zijn scripts bedoeld om uitgevoert te worden bij het opstarten van het systeem.

# Paketten
## System Logger
De gebruikte system logger is `sysklogd`. Een system logger is er om bij te houden wat je systeem doet, de logger zet elke actie in een een log-bestand die je kunt bekijken wanneer je maar wilt.
### Alternatief
`Metalog` is een van de alternatieven voor sysklogd. Het voornaamste verschil ligt in de configureerbaarheid.

## Cron Deamon
`Cronie` is de geinstalleerde cron-deamon. Cron-deamons worden gebruikt om taken te schedulen om ze met regelmaat uit te voeren, bijvoorbeeld elke dag om 14:00 of elke maand op de eerste donderdag.
### Alternatief
`Fcron` is een alternatief voor Cronie die veel configureerbaarder is dan Cronie.

## File Indexer
`Mlocate` is geïnstalleerd als file-indexer. File-indexers doen precies wat de naam zegt, je bestanden indexeren, daarna wordt de index opgeslagen in een database. De functionaliteit is vergelijkbaar met `find`, alleen kijkt `locate` standaard over je gehele systeem.
### Alternatief
`find` is een mogelijk alternatief, maar kijkt standaard alleen in het opgegeven pad.

# Booten (revisited)
Als bootloader heb ik `GRUB` gekozen vanwege zijn versitaliteit. Grub is makkelijk in te stellen en compatibel met vrijwel alle systemen.

# Afronden
Hij kan het filesystem niet herkennen waardoor ik niet kan rebooten. Zo kan ik dus ook geen window-manager en/of desktop-environment installeren en werkend krijgen. Verder werkt het.

Ik gebruik linux full-time op mijn laptop en heb genoeg ervaring met onder andere Plasma en Gnome. Ook heb ik LXDE en Xfce gebruikt en heel even i3 en Awesome gebruikt en spoedig ondervonden dat tiling window-managers niet voor mij weggelegd zijn.
## Vergelijking van WM's en DE's
__Plasma__ staat op de tweede plaats van DE's qua impact op je systeem, het werkt vrij vlot en is Windows-achtig. De configureerbaarheid is extreem hoog zoals gebruikelijk is voor KDE-software.

__Gnome__ staat onderaan qua performance, het is prima te gebruiken desondanks. Je hebt een redelijk aantal mogelijke aanpassingen te maken maar lang zoveel niet als je hebt met KDE. Gnome-software heeft meer de neiging om hetgeen ze doen uitstekend te doen.

__LXDE__ is de lichtste DE. Het is Windows-achtig en heeft niet bepaald een moderne uitstraling. Het is de standaard DE van Raspbian, dit vanwege de lage impact op de systeem resources.

__i3__ en __Awesome__ zijn tiling window-managers. Dit betekend dat ze geen overlap toestaan van vensters (behalve wanneer je de optie aan zet, voorzover ik weet heeft Awesome die). Deze zijn licht van gewicht en bijna eindeloos configureerbaar. Deze configuratie gaat via scripts en je kunt het laten doen en tonen wat je wilt.