//uniform lowp vec4 unif_color;
varying mediump vec4 out_color;
uniform sampler2D texture;
varying mediump vec2 vary_uv;
void main() {
    gl_FragColor = texture2D(texture, vary_uv);
    //gl_FragColor = out_color;
}