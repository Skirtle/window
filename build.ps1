# build.ps1
# Compiles main.cpp + Glad + GLFW into app.exe and runs it in the same console if successful

# Paths
$GLFW_INCLUDE = "C:/glfw-3.4.bin.WIN64/include"
$GLFW_LIB     = "C:/glfw-3.4.bin.WIN64/lib-mingw-w64"
$GLAD_INCLUDE = "external/glad/include"
$GLAD_SRC     = "external/glad/src/glad.c"
$MAIN_SRC     = "src/main.cpp"
$OUTPUT       = "app.exe"

# Compile
Write-Host "Compiling $MAIN_SRC..."
g++ "$MAIN_SRC" "$GLAD_SRC" `
    -I"$GLAD_INCLUDE" `
    -I"$GLFW_INCLUDE" `
    -L"$GLFW_LIB" `
    -lglfw3 -lopengl32 -lgdi32 `
    -o "$OUTPUT"

# Check if compilation succeeded
if ($LASTEXITCODE -eq 0) {
    Write-Host "Compilation successful! Running $OUTPUT..."
    & .\$OUTPUT
} else {
    Write-Host "Compilation failed."
}
