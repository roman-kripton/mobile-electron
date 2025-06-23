{
  "variables" : {
    "openssl_fips": "",
  },
  "targets": [
    {
      "target_name": "focus",
      "sources": [
        "source/bindings.cc"
      ],
      "conditions": [
        [
          "OS==\"win\"",
          {
            "sources": [ "source/focus_win.cc" ]
          }
        ],
        [
          "OS!=\"win\"",
          {
            "sources": [ "source/focus_noop.cc" ]
          }
        ]
      ]
    }
  ]
}
