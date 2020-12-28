const app = getApp();
var id = null;
var index = null;
var items = [];

Page({
  data: {
    showDialog:false,
    items:[],
  },

  onLoad: function (options) {
    id = options.id.toString();
    index = options.index;
    console.log('received id:'+id+' index:'+index);
    items = app.globalData.classlist[index].children[id],
    this.setData({
      items: items,
    })
    this.priceCount();
    console.log(items);
  },
  toLastPage: function(){
    wx.navigateBack({
      success: function(){
        // beforePage.onLoad();
        console.log('回到分类页面 index:'+index);
      }
    })
  },
  toCart: function(){
    wx.switchTab({
      url: '/pages/cart/cart',
    })
  },
  // 购物车弹框弹出
  toggleDialog: function () {
    console.log("加入购物车弹窗开启");
    this.setData({
      showDialog: !this.data.showDialog
    })
  },
  // 购物车弹框关闭
  closeDialog: function () {
    console.info("弹窗关闭");
    this.setData({
      showDialog: false
    });
  },
  /* 减数 */
  delCount: function (e) {
    console.log("刚刚您点击了减1");
    var count = this.data.items.count;
    // 商品总数量-1
    if (count > 1) {
      this.data.items.count--;
    }
    // 将数值与状态写回  
    this.setData({
      items: this.data.items
    });
    this.priceCount();
  },
  /* 加数 */
  addCount: function (e) {
    console.log("刚刚您点击了加1");
    var count = this.data.items.count;
    // 商品总数量-1  
    if (count < 10) {
      this.data.items.count++;
    }
    // 将数值与状态写回  
    this.setData({
      items: this.data.items
    });
    this.priceCount();
  },
  //价格计算
  priceCount: function (e) {
    this.data.items.totalMoney = this.data.items.price * this.data.items.count;
    this.setData({
      items: this.data.items
    })
  },
  addCar: function(e){
    var items = this.data.items;
    items.isSelect = false;
    var count = this.data.items.count;
    var name = this.data.items.name;
    if(name.length>13){
      items.name = name.substring(0,13)+'...';        
    }
    var arr = wx.getStorageSync('cart') || [];
    console.log(arr);
    if(arr.length > 0){
      for(var j in arr){
        if(arr[j].item_id == id){
          arr[j].count = arr[j].count + this.data.items.count;
          try{
            wx.setStorageSync('cart',arr);
          }
          catch(e){
            console.log(e);
          }
          // 购物车已有该物品加入成功
          wx.showToast({
            title: '加入购物车成功!',
            icon:"success",
            duration:2000
          })
          //关闭弹窗，结束function
          this.closeDialog();
          return;
        }
      }
      arr.push(items);
    }
    else{
      arr.push(items);
    }
    try {
      wx.setStorageSync('cart', arr)
      // 返回（在if内使用return，跳出循环节约运算，节约性能） 
      //关闭窗口
      wx.showToast({
        title: '加入购物车成功！',
        icon: 'success',
        duration: 2000
      });
      this.closeDialog(); 
      return;
    } catch (e) {
      console.log(e)
    }
  },
  immeBuy(){
    wx.showToast({
      title: '尚未完善',
      icon: 'loading',
      duration: 2000
    });
  }
})