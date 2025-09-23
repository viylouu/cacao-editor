cd cacao
git checkout -- .
cd ..
git submodule update --remote --init --recursive
rm -rf data/eng
cp -r cacao/data/eng data/eng

