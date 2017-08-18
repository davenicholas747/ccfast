// index.js

'use strict'

const cli = require('./build/Release/cc_bitcoincli')

console.log(`${cli.BitcoinCli('getinfo')}`)
console.log(`${cli.BitcoinCli('getblock', '0000000008e647742775a230787d66fdf92c46a48c896bfbc85cdc8acc67e87d')}`)
console.log(`${cli.BitcoinCli('getrawtransaction', 'fe28050b93faea61fa88c4c630f0e1f0a1c24d0082dd0e10d369e13212128f33')}`)


