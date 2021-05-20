 #!/bin/sh

source /home/makodz/mpdroot/mpdroot/build/config.sh
cd /home/makodz/work/mpd/
mkdir gen.$1
cp ./TestEvUrqmd.template/inputfile gen.$1/
ln -s /home/makodz/urqmd-3.4/urqmd.x86_64 gen.$1/urqmd.x86_64
cd gen.$1
/home/makodz/urqmd-3.4/runqmd.bash
gzip test.f14
cd ../
mkdir TestEvUrqmd.$1
cd TestEvUrqmd.$1
ln -s ../gen.$1/test.f14.gz test.f14.gz
cp ../TestEvUrqmd.template/runMC.C .
cp ../TestEvUrqmd.template/runreco.sh .
. runreco.sh
cd ../
