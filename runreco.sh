#!/bin/bash

source /home/makodz/mpdroot/mpdroot/build/config.sh
cd /home/makodz/work/TestEvUrqmd.$1
root -b -q runMC.C
cp /home/makodz/work/mpd/TestEvUrqmd.template/reco.C .
root -b -q reco.C
