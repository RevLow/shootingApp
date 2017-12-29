attribute mediump vec4 attr_pos;
// uniform mediump vec3 unif_pos;
attribute mediump vec4 attr_color;
attribute mediump vec2 attr_uv;
varying mediump vec4 out_color;
varying mediump vec2 vary_uv;

void main() {
    gl_Position = attr_pos;
    out_color = attr_color;
    vary_uv = attr_uv;
    //gl_Position.xyz += unif_pos;
}