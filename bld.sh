echo "CC: Clearing out old build relics..."
node-gyp clean
node-pre-gyp clean

rm -rf build
rm -rf node_modules

npm -l install node-pre-gyp-github

node-gyp --target=v8.1.4 configure
node-pre-gyp build
node-pre-gyp package

echo ""
echo ""
echo "Testing package..."

#node-pre-gyp testpackage

#node-pre-gyp-github publish
#export NODE_PRE_GYP_GITHUB_TOKEN=192387be34b4ce3d39ffc42769b172ccd27b923a

node-pre-gyp-github publish --release

echo "cc: Run smoke test on addon...."

node index.js

echo "CC Done!"






