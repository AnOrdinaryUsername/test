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

Create a C++ file with functions that you want to expose to JavaScript.

```cpp
#include <emscripten/bind.h>

using namespace emscripten;

float functionName(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("functionName", &functionName);
}
```

Using Emscripten run the following command in bash to create js glue code from C++ code.

> Note: This also generates a WASM file that contains the binary code. Make sure to put yellowProject.js and yellowProject.wasm in the same folder.

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

In yourJavaScriptCode.js, you can call C++ functions with the global Module object from Emscripten's generated file, "yellowProject.js". Here's an example using the C++ function, `functionName()`, in "yourJavaScriptCode.js".

```javascript
console.log(Module.functionName(3.24, 4.5, 0.8));
```

But before you can see the result, run a local server using Python.

```bash
# if your version is 2.x
python -m SimpleHTTPServer 8080

# if your version is 3.x
python -m http.server 8080
```

Go to http://localhost:8080/, click on the dist/ link, right-click + inspect element, and go to the console tab. It should display "4.248".

### Running our project

To run our project all you have to do is clone the repo.

```bash
git clone https://github.com/AnOrdinaryUsername/Transposition-Cipher.git
```

And run a local server to get started!

You can also visit [the website](https://anordinaryusername.github.io/test/) if you don't want to run it locally.
