#!/bin/bash
# script_tput.sh

#### Initialisation des variables ####

#+ Mode normal
resetColor=$(tput sgr0)

#- Rouge
bcRed=$(tput setab 1)

#- Black
bcBlack=$(tput setab 0)