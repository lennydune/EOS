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

![Partitieschema](http://cooledomeinnaam.nl/Partitieschema.png)

Ik heb het schema gemaakt met Parted en geen geadvanceerde opties gebruikt.

# Het basissysteem
Geen opmerkingen.

# Configuratie
## CFLAGS, CXXFLAGS en MAKEOPTS
> The CFLAGS and CXXFLAGS variables define the optimization flags for GCC C and C++ compilers respectively. Although those are defined generally here, for maximum performance one would need to optimize these flags for each program separately.

> The MAKEOPTS variable defines how many parallel compilations should occur when installing a package. A good choice is the number of CPUs (or CPU cores) in the system plus one, but this guideline isn't always perfect.

`MAKEOPTS="-j3"` in plaats van `"-j2"`. Dit omdat de VM 2 cores heeft en er is aangeraden om het aantal CPU's te nemen + 1.

## @World
`@world` omvat de sets `@system` en `@selected`. `@system` is de set waar alle paketten in zitten die vereist zijn om het systeem te laten werken. `@selected` is de set waar alle paketten in zitten die de admin heeft geselecteerd.

Het updaten van `@world` op dit punt zorgt ervoor dat je een up-to-date systeem hebt om mee verder te werken.

## USE Variabele
`USE="acl amd64 berkdb bzip2 cli crypt cxx dri fortran gdbm iconv ipv6 libtirpc ncurses nls nptl openmp pam pcre readline seccomp ssl tcpd unicode xattr zlib"` is de default voor de `USE` variable. Ik heb `avahi zsh-completion` toegevoegd.
* __Avahi__ is handig omdat ik dan bij het systeem kan komen met `ssh root@hostname.local` in plaats van `ssh root@ip.van.de.host`.
* __Zsh-completion__ omdat ik een groot fan ben van zsh en dat ga installeren zodra we zover zijn, en auto-completion kan ik waarderen.

## Kernel Configuratie
De opties die ik heb gekozen zijn de defaults van [het handboek](https://wiki.gentoo.org/wiki/Handbook:AMD64/Full/Installation#Activating_required_options)

## fstab

## rc-update en init-scripts

# Paketten


# Booten (revisited)


# Afronden
