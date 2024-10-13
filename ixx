#!/bin/env bash

#source "$(which i3s)"
#st -c "nnn-renamer" -e "qmv --format destination-only ${@}" &
st -c "nnn-renamer" -e qmv $1
#st -c "nnn-renamer" -e "qmv --format destination-only ${@}" &

# prgs ################################################

_st()      { st -c "$class" $@ & sleep 0.4; }
_stx()     { st -c ${@} & }
_sti()     { st -c "${1}" zsh -i -c "${2}" & }
_nvx()     { nvim -c "lua require'auto.odo'.${1}()"; }
_nvs()     { st -c "${1}" -e nvim -c "lua require'auto.odo'.${2}()" ; }
_nvf()     { _xxf "${1}" 'st -c '"${1}"' -e nvim -c "lua require'\''auto.odo'\''.'${2}'()"'; }
_voa()     { _nvs voa oa & }
_vma()     { _nvs vma ma & }
_vmj()     { _nvs vmj mj & }
_vml()     { _nvs vml ml & }
_vfoa()    { _nvf vfoa oa & }
_vfma()    { _nvf vfma ma & }
_vfua()    { _nvf n0 ua & }
_vfub()    { _nvf n1 ub & }
_nnf1()    { _stf "nnn1" 'nnn -a'; }
_nnf2()    { _stf "nnn2" 'nnn -a'; }
_nnf3()    { _stf "nnn3" 'nnn'; }
_vds_ev()  { st -c ds   -e nvim ~/d/ds/ev --cmd "cd ~/d/ds/ev" ; }
_mutt_ix() { st -c "mlx" neomutt -e "push '<change-folder>=ii<enter>'" & }
_mutt_iy() { st -c "mlx" neomutt -e "push '<change-folder>=ii<enter><sidebar-toggle-visible><enter>'" & }
_mutt_ib() { st -c "mlx" neomutt -e "push '<change-folder>=ii<enter>bibu'" & }
_mutt_ii() { _mutt_ix; }
_qb_o365() { qb win "https://outlook.office365.com/mail/" & }
_qb_gpt()  { qb win "https://chat.openai.com" & }
_qb_mlcx() { qb win "contacts.google.com" & }
_qb_mlcy() { qb tab "https://outlook.office365.com/people/" & }
_qb_cal()  { qb win "https://calendar.notion.so/" & }
_qb_noti() { qb win "https://notion.so/" & }
_qb_ml()   { _qb_gpt; }
_qb_mlpv() { qb m; }
_au_fl()   { st -c "music-float" -e vimpc & }
_au()      { st -c "music" -e vimpc & }
_nnn()     { st -c nnn -e nnn & }
_nnf1()    { _stf "nnn1" 'nnn -a'; }
_nnf2()    { _stf "nnn2" 'nnn -a'; }
_nnf3()    { _stf "nnn3" 'nnn'; }
_rename()  { st -c "nnn-renamer" -e qmv --format destination-only ${1} & }

_ml_split() {

  _mutt_ii
  sleep 3
  i3-msg '[class="mlx"] focus'
  i3-msg "split h"
  _qb_mlpv
  sleep 3; i3-msg "focus right" ;}



# spaces ##################################################


_ws_oo() {
  _l_tabd
  _qb_cal
  _voa ;}

_ws_ml() {
  _l_tabd
  _qb_ml
  _mutt_ii
  _vml ;}

_ws_ai()     { _qb_gpt; }
_ws_mj()     { _vma; }
_ws_au()     { _st; _au; }
_ws_sx()     { _st; }
_ws_sy()     { _st; }
_ws_rd()     { _nnn; } #todo: create custom workspace for academic reading (focused)
_ws_ds()     { _st "nvim ~/d/ds/ev --cmd "cd ~/d/ds/ev""; }
_ws_fl_ai()  { _ws_x "flai" "3" "_ws_ai"; }
_ws_fl_oo()  { _ws_x "floo" "4" "_ws_oo" ;}
_ws_fl_mk()  { _ws_x "flmk" "3" "_ws_mk" ;}
_ws_fl_ml()  { _ws_x "flml" "3" "_ws_ml" ;}
_ws_fl_mj()  { _ws_x "flmj" "3" "_ws_mj" ;}
_ws_fl_au()  { _ws_x "flau" "2" "_ws_au" ;}
_ws_fl_sx()  { _ws_x "flsx" "2" "_ws_sx" ;}
_ws_fl_sy()  { _ws_x "flsy" "2" "_ws_sy" ;}
_ws_fl_ds()  { _ws_x "flds" "2" "_ws_ds" ;}
_ws_ab_rd()  { _ws_y "xrd" "_ws_rd";}
_ws_ab_au()  { _ws_y "xau" "_ws_au";}
_ws_ab_ai()  { _ws_y "xai" "_ws_ai";}
_ws_ab_sx()  { _ws_y "xsx" "_ws_sx";}
_ws_ab_sy()  { _ws_y "xsy" "_ws_sy";}
_ws_ab_sy()  { _ws_y "xds" "_ws_ds";}
_ws_ab_oo()  { _ws_y "xoo" "_ws_oo";}
_ws_ab_mj()  { _ws_y "xmj" "_ws_mj";}
_ws_ab_mk()  { _ws_y "xmk" "_ws_mk";}
_ws_ab_ml()  { _ws_y "xml" "_ws_ml";}


_ws_ml_contain() { # TODO: container & non-floating, within any workspace 'x'

  _wcont_init
  _ws_ml
  _wcont ;}


# URLS #######################################
# TODO: separate personal program configs into separate file

urls=()
url_soc_a() {
    urls+=("https://www.facebook.com/iarom.ma")
    urls+=("https://www.instagram.com/iarom.madden/")
}
url_soc_b() {
    url_soc_a
    urls+=("https://twitter.com/imaddsy")
    urls+=("https://publish.socialchamp.io/app/v2/engage/inbox?itemType=all&itemStatus=unread")
}
url_oo() {
    urls+=("notion.so")
    urls+=("https://chat.openai.com/chat")
}
url_oox() {
    # calendar.google.com opened with norestore func
    urls+=("contacts.google.com")
    urls+=("calendar.google.com")
    urls+=("https://habitica.com/")
}
url_cm_a() {
    urls+=("web.whatsapp.com")
    urls+=("https://business.facebook.com/latest/inbox/")
}


# SPECIFIC SPACES ###############################

q_wa() { qb xwin web.whatsapp.com ;}
w_xx() { qb win chat.openai.com; }
w_xy() {
    qb win notion.so
    #qb x win calendar.google.com & sleep 2s
    #qb w.oo.wins & sleep 3s
    #qb win notion.so & sleep 2s
    #qb tab notion.so
    #firefox calendar.google.com & # firefox to avoid qtwebengine issues with these sites
        # just use morgen for the mo
    #qb tab chat.openai.com
}


# POMODORO ###########################################

_pomx() {
    for R in $(printf "%s\n" "$poms" | grep R -o); do
        read -r line
        echo "$(pomo status)" || exit 1
    done ;}


_pomf1() { poms=$(pomodoro status --format "%R ⏱ %c/%g 🍅\n%d"); }
_pomf2() { poms=$(pomo status); }
_pom1()  { _pomf1; _pomx;}
_pom2()  { _pomf2; _pomx;}


# workspaces ####################

_main() {
    
    cmd="$1" && [ -n "$1" ] && shift 1
    
    #_ini
    
    case ${cmd} in
        # workspace float
        flai|ws.flai)     _ws_fl_ai ;;
        floo|ws.floo)     _ws_fl_oo ;;
        flds|ws.flds)     _ws_fl_ds ;;
        flmj|ws.flmj)     _ws_fl_mj ;;
        flmk|ws.flml)     _ws_fl_mk ;;
        flml|ws.flml)     _ws_fl_ml ;;
        flau|ws.flau)     _ws_fl_au ;;
        flrd|ws.flrd)     _ws_fl_rd ;;
        flsx|ws.flsx)     _ws_fl_sx ;;
        flsy|ws.flsy)     _ws_fl_sy ;;
        # workspace
        wxai)             _ws_ab_ai ;;
        wxoo)             _ws_ab_oo ;;
        wxmj)             _ws_ab_mj ;;
        wxmk)             _ws_ab_mk ;;
        wxml)             _ws_ab_ml ;;
        wxau)             _ws_ab_au ;;
        wxrd)             _ws_ab_rd ;;
        wxsx)             _ws_ab_sx ;;
        wxsy)             _ws_ab_sy ;;
        # windows
        voa)              _voa ;;
        vma)              _vma ;;
        vma)              _vma ;;
        vfoa)             _vfoa ;;
        vfma)             _vfma ;;
        vfua)             _vfua ;;
        vfub)             _vfub ;;
        # apps nnn
        nn1)              _nnf1 ;;
        nn2)              _nnf2 ;;
        nn3)              _nnf3 ;;
        # apps
        au)               _au ;;
        w.ml)             _mutt_ii ;;
        w.mlb)            _mutt_ib ;;
        pomx)             _pomx ;;
        pomy)             _pomy ;;
        # new
        r|rename)         _rename "${@}" ;;
        # fallback
        *|custom)         ${@} ;;
    esac }


_main ${@}

exit
# TODO: feed a list of urls to qb to setup various browser workspaces
# - Perhaps save them within /tmp/qbx as an intermediary structure of 
# indices
    # workspaces
    case $cmd in
        w.soc)            url_soc_b; _qx_win "${@}" ;;
        w.oo)             url_oo; q_win "${@}" ;;
        w.oo.wins)        url_oo; q_wins "${@}" ;;
        w.cm)             url_cm_a; _qx_win "${@}" ;;
        w.cm.ml)          url_cm_a; url_soc_a; _qx_win "${@}";;
    esac
# ###################################################
#firefox --new-window betterhelp.com &
#qb win betterhelp.com & sleep 4s
#qb w.oo & morgen &
# TODO: read only nmutt? #st -c tabbedx neomutt -e "push '<change-folder>=ii<enter>'" &
# TODO: vary sleep based on qb status (initiated or not)
#
# ###################################################
#alias _nv="nvim -c lua require'auto.odo'.$1()"
#_nv()      { nvim -c "edit a"; }
