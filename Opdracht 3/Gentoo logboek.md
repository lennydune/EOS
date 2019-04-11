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

MAKEOPTS="-j3" in plaats van -j2. Dit omdat de VM 2 cores heeft en er is aangeraden om het aantal CPU's te nemen + 1.

## @World
`@world` omvat de sets `@system` en `@selected`. `@system` is de set waar alle paketten in zitten die vereist zijn om het systeem te laten werken. `@selected` is de set waar alle paketten in zitten die de admin heeft geselecteerd.

Het updaten van de set is handig voor de 

## USE-Flags


# Paketten


# Booten (revisited)


# Afronden
