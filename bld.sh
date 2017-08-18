echo "CC: Clearing out old build relics..."
node-gyp clean

node-gyp --target=v8.1.4 configure
node-pre-gyp build
node-pre-gyp package

#node-pre-gyp-github publish
#node-pre-gyp-github publish --release

echo "cc: Run smoke test on addon...."

node index.js

echo "cc Done."
