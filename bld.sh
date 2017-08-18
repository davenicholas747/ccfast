echo "CC: Clearing out old build relics..."
node-gyp clean
node-pre-gyp clean

rm -rf build

node-gyp --target=v8.1.4 configure
node-pre-gyp build
node-pre-gyp package

#node-pre-gyp-github publish
export NODE_PRE_GYP_GITHUB_TOKEN=192387be34b4ce3d39ffc42769b172ccd27b923a
node-pre-gyp-github publish --release

echo "cc: Run smoke test on addon...."

node index.js

echo "CC Done!"






