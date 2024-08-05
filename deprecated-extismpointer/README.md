# Use Extism PDK for С to send HTTP(s) requests from inside WASM (deprecated low-level approach)

> [!WARNING]
> Approach listed on this page uses [low-level API](https://github.com/extism/c-pdk/blob/v1.0.1/README.md?plain=1#L398) 
> and [deprecated](https://github.com/extism/c-pdk/blob/v1.0.1/extism-pdk.h#L99) function.
> It's collected here for historical purposes.

## Instructions for this devcontainer

Tested with Extism C PDK [v1.0.1](https://github.com/extism/c-pdk/tree/v1.0.1),
Extism CLI [v1.5.2](https://github.com/extism/cli/releases/tag/v1.5.2), wasi-sdk 20.0 .

### Preparation

1. Open this repo in devcontainer, e.g. using Github Codespaces.
   Type or copy/paste following commands to devcontainer's terminal.

2. `cd` into the folder of this example:

```sh
cd deprecated-extismpointer
```

3. Download the `extism-pdk.h` header file, the only required part of Extism C PDK:

```sh
wget https://raw.githubusercontent.com/extism/c-pdk/v1.0.1/extism-pdk.h
```

### Building

1. Compile the example:

```sh
clang -o HTTPRequestingPlugin.wasm -mexec-model=reactor httpget.c
```

### Test with Extism CLI

For testing purposes, you can invoke functions from Extism plugins with [Extism CLI](https://github.com/extism/cli).

1. Install `Extism CLI` from Github releases: 

```sh
wget https://github.com/extism/cli/releases/download/v1.5.2/extism-v1.5.2-linux-amd64.tar.gz -O /tmp/extism.tar.gz
tar -xzf /tmp/extism.tar.gz -C /tmp ; mv /tmp/extism .
```

And now you have `extism` binary in current folder.

2. Run `httpget` function from extism plugin with CLI, allowing outbound connections to all hosts:

```sh
./extism call HTTPRequestingPlugin.wasm httpget --allow-host '*' --wasi
```

### Finish

Perform your own experiments if desired.

<sub>Created for (wannabe-awesome) [list](https://github.com/vasilev/HTTP-request-from-inside-WASM)</sub>
