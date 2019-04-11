# Booten
Voor het booten heb ik geen extra boot-opties aangegeven. Ik heb een VM met een virtuele ethernetverbinding die voor internet zorgt, dus dat werk out-of-the-box. Daarna heb ik ssh opgestart omdat de terminal van de VM zeer traag is met text printen, dit vertraagt alle commands die veel text naar stdout gooien (zoals tar of emerge).

# De harde schijf
## Verschillen tussen MBR en GPT
MBR - Master Boot Record | GPT - GUID Partition Table
------------------------ | --------------------------
Maximaal 4 primary partities | Detectie voor datacorruptie
---------------------------- | ---------------------------
Max 2TB per partitie | In theorie oneindige partities
-------------------- | ------------------------------
  | Beperkt door de OS
-   ------------------
  | Windows heeft 128 als max

Het partitieschema ziet er als volgt uit:

![Partitieschema](http://cooledomeinnaam.nl/Partitieschema.png)

Ik heb het schema gemaakt met 

# Het basissysteem


# Configuratie


# Paketten


# Booten (revisited)


# Afronden
