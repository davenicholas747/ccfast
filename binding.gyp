{
  "targets": [
    {
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],

      "target_name": "cc_bitcoincli",

      "sources": [ "src/cliclient.cpp", "../../../../bitcoin/src/cliboilerplateforaddon.cpp"],
   
      "libraries" : ["~/projects/opensource/bitcoin/src/libbitcoin_cli.a",
                     "~/projects/opensource/bitcoin/src/libbitcoin_util.a",
                     "~/projects/opensource/bitcoin/src/crypto/libbitcoin_crypto.a",
                     "~/projects/opensource/bitcoin/src/libbitcoin_server.a",

                     "/usr/local/lib/libunivalue.a",

                     "/usr/lib/x86_64-linux-gnu/libboost_atomic.so",
                     "/usr/lib/x86_64-linux-gnu/libboost_chrono.so",
                     "/usr/lib/x86_64-linux-gnu/libboost_date_time.so",
                     "/usr/lib/x86_64-linux-gnu/libboost_filesystem.so",
                     "/usr/lib/x86_64-linux-gnu/libboost_prg_exec_monitor.so",
                     "/usr/lib/x86_64-linux-gnu/libboost_program_options.so",
                     "/usr/lib/x86_64-linux-gnu/libboost_serialization.so",
                     "/usr/lib/x86_64-linux-gnu/libboost_system.so",
                     "/usr/lib/x86_64-linux-gnu/libboost_thread.so",
                     "/usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so",
                     "/usr/lib/x86_64-linux-gnu/libboost_wserialization.so",
                     "/usr/lib/x86_64-linux-gnu/libevent.so"
                    ],

      "cflags_cc": [ "-fexceptions","-fpermissive"]

    }
  ]
}

