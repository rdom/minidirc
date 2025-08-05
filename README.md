## Installation
```
#install and initialize geant4 with -DGEANT4_USE_OPENGL_X11=ON -DGEANT4_USE_QT=ON

git clone https://github.com/rdom/minidirc
cd minidirc
mkdir build
cd build
cmake ..
make -j4


#test event display
 ./mdirc -x ion -ionz 90 -e 1
```


## Synopsis
```
mdirc [OPTION] [ARGUMENT] ... [OPTION] [ARGUMENT]

example:
./mdirc -x ion -ionz 90 -p 9000 -theta 90 -e 10 -b 1

```
## Options
```
-o    output file name
-i    input file name
-u    look-up file name
-pdf  PDFs file name
-nn   path to the neural network

-r    run type
                0    simulation
                1    look-up table generation
                2    geometrical reconstruction and time imaging
                3    likelihood calculation
		4    create pdf
		5    simulate pdf
		20   2 with Cherenkov ring fit 

-field    field type
                0    no field (default)
                1    CORE b-field
                2    ePIC MARCO 1.7T
                3    ePIC MARCO 2.0T
		4    solenoidal 3.0T

-g    geometry configuration
                0    Mini Dirc (default)
		
-ev   expansion volume type
	        0    prism with lenses (default)
                1    BaBar wedge with focusing prism
                3    prism with plate, lens between bars and plate
		4    tilted EV
		5    prism with plate, lens between plate and EV
		6    split prism
		7    prism with thicker plate (shifted to center), lens between bars and plate
		8    split prism with split plate, lens between plate and EV
		9    split prism with split plate, lens between bars and plate

-h    number of bars in one radiator box (use with "-g 0")

-c    PMT layout
                0    one PMT (20 mm x 20 mm) (default)
                4    one PMT covering whole back of EV
		
-l    focusing system
                0    no lens
                3    3-layer spherical lens (default)
                6    3-layer cylindrical lens
                10   ideal lens (thickness = 0, ideal focusing)

-theta    polar between particle beam and bar radiator [deg]
                90 default
                if theta == 0 then theta = [30,160]

-phi  azimuth angle between particle beam and bar radiator [deg]
                0 default
		use [990, 999] (corresponds to bar # [0,9]) to choose which bar should be hit (works also with -field 2, for > ~4 GeV/c)
		same use of [990, 999] for LUT generation		

-gs  Gaussian sigma of the beam size (in X and Y) [mm]
                0 (default)

-e    number of simulated events

-x    particle type
              ion default)
              "pi+"
              "proton"
              "kaon+"
                 ...
              "opticalphoton"
	      "mix_pie"  1 pion 1 electron mix
	      "mix_pimu" 1 pion 1 muon mix
              "mix_pik"  1 pion 1 kaon mix
	      "mix_pip"  1 pion 1 proton mix
	      "mix_kp"   1 kaon 1 proton mix

-ionz Z of the ion
               90 (default)
	      
-p    particle momentum [GeV/c]
      9000 (default)

-w    physical list
                0    standard EM (default)
                1    without multiple scattering and bremsstrahlung
		2    standard EM with HAD (elastic/inelastic/absorption)
		3    FTFP_BERT
                10   monochromatic Cherenkov light
                11   10 + 1 

-seed seed number for the random generator 

-b    batch mode
               1    run silent (without GUI)

-d    display option
               don't use this argument, instead use /Prt/geom/drawHits 2 
               0    standard (default)
               1    display hit occupancy of current run
               2    display hit occupancy of occuhits.root (needs to be generated)

-timeres   time resolution [ns]
               0.1  (default)

-timecut   time cut constant [ns]
               0.5  (default)  

-trackingres   tracking resolution [rad], applied at tracking layer
               0.0005  (default)
	       100 use realistic, mapped values

-cor           per-pmt correction
               0 without correction
	       1 apply Cherenkov angle correction
	       2 apply Cherenkov angle and time corrections (default)
	       5 (re)create corrections

-gx beam's X offset [mm]
               0 default

-gy beam's Y offset [mm]
               0 default

-gz beam's Z offset [mm]
               0 default

-dn dark noise per PMT
               amount of dark noise hits per-pmt [Hz]

-t1            test variable
               [double]

-t2            test variable
               [double]

-t3            test variable
               [double]

-m geant4 macro
                path to geant4 macro (must have .mac extension e.g. cuts.mac)

```

![alt text](https://raw.githubusercontent.com/rdom/minidirc/refs/heads/main/pic/mdirc_4.png)


## Example of script usage from macro folder

Hit pattern:

```
cd minidirc/build
./mdirc -x ion -ionz 90 -e 10 -b 1
cd minidirc/macro
root draw_hp.C'("../build/hits.root")'
```
Example of 10 ions (Z = 90) with 9000 GeV/c momentum  @ 90 degree:

![alt text](https://raw.githubusercontent.com/rdom/minidirc/refs/heads/main/pic/hp.png)
