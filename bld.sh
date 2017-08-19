echo "CC: Clearing out old build relics..."
node-gyp clean
node-pre-gyp clean
rm -rf build
rm -rf node_modules
rm -rf /home/dave/node_modules/cc_bitcoincli

npm -l install node-pre-gyp-github

node-gyp --target=v8.1.4 configure
node-pre-gyp build
node-pre-gyp package

echo ""
echo ""
echo "Testing package..."

#node-pre-gyp testpackage
export NODE_PRE_GYP_GITHUB_TOKEN=5e18930060f56e93fbf26496fbf6abf27fe6dac4

echo ""
echo ""
echo ""
echo "Running node-pre-gyp-github publish now ...."
node-pre-gyp-github publish --release

#node-pre-gyp publish

echo "cc: Run manual smoke test on addon...."
node index.js
echo "CC Done!"






