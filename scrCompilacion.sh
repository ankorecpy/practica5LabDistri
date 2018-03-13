rpcgen $1.x

rm -rf cliente
rm -rf servidor

mkdir cliente
mkdir servidor 

cp $1.x cliente
cp $1.h cliente
cp $1.x servidor
cp $1.h servidor 
rm $1.h

cp $1_clnt.c cliente
rm $1_clnt.c
cp $1_svc.c servidor
rm $1_svc.c

