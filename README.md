# WebAssembly

<img alt="WebAssembly logo" src="https://upload.wikimedia.org/wikipedia/commons/1/1f/WebAssembly_Logo.svg" width="60" />

## How to use CPP files in a web page

### Installing Emscripten

To get started, run these commands.

```bash
git clone https://github.com/emscripten-core/emsdk.git

cd emsdk
```

Now follow the rest of the guide [here](https://emscripten.org/docs/getting_started/downloads.html).

### Using Emscripten

Using Emscripten run the following command in bash to create js glue code from C++ code.

> Note: This also generates a WASM file that contains the binary code. Make sure to put yellowProject.cpp and yellowProject.wasm in the same folder.

```bash
emcc --bind -o yellowProject.js yellowProjectWasm.cpp
```

Add the yellowProject.js to a `<script>` element in an HTML file.

```html
<body>
  <!-- HTML elements here -->

  <script src="yellowProject.js"></script>
  <!-- JavaScript code that uses C++ functions -->
  <script src="yourJavaScriptCode.js"></script>
</body>
```

Run a local server using Python.

```bash
# if your version is 2.x
python -m SimpleHTTPServer 8080

# if your version is 3.x
python -m http.server 8080
```

Go to http://localhost:8080/ to run you C++ functions!

### Running our project

To run our project all you have to do is clone the repo.

```bash
git clone https://github.com/AnOrdinaryUsername/Transposition-Cipher.git
```

And run a local server to get started!
