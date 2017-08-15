node-gyp clean
node-gyp --target=v8.1.4 configure
node-gyp build

echo "cc: Run smoke test on addon...."

node index.js

echo "cc Done."
